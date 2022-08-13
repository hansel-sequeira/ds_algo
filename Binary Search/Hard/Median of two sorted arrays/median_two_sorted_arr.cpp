double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n2 < n1) return findMedianSortedArrays(nums2, nums1); //This line is necessary only if you want tc to be O(log(min(m,n))
        //int k = (n1+n2+1)/2;     Relate this problem to finding the kth element among 2 sorted arrays
        //if(n2 < k) low = k - n2;
        //if(n1 > k) high = k;
        int low = 0, high = n1;
        while(low<=high){
            int cut1 = low+(high-low)/2;
            int cut2 = (n1+n2+1)/2 - cut1;
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            if(l1<=r2 and l2<=r1){
                if((n1+n2)%2 == 0) return (max(l1,l2) + min(r1,r2))/2.0;
               else return max(l1,l2);
            }
            else if(l1>r2) high = cut1-1;
            else low = cut1+1;
        }
        return -1;
    }

//TC: O(log(n)) where n = min(n1,n2)
