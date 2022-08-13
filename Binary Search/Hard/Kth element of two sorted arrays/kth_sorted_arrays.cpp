int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m) return kthElement(arr2, arr1, m, n, k);
        int low = 0, high = n;
        if(k < n) high = k; //edge case 1: if n = 5 and k = 2, obviously at max 2 element will be taken from arr1.
        if(k > m) low = k-m; //edge case 2: if m = 5 and k = 7, then when low = 0, 7 elts need to be taken from arr2 which isn't possible.
        while(low<=high){
            int cut1 = low+(high-low)/2;
            int cut2 = k-cut1;
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];
            if(l1<=r2 and l2<=r1){ //correct point
                return max(l1, l2);
            } else if(l1 > r2) high = cut1-1;
            else low = cut1+1;
        }
        return -1;
    }
