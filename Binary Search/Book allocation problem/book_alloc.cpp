
/*
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:{12} and {34, 67, 90} 
Maximum Pages = 191{12, 34} and {67, 90} 
Maximum Pages = 157{12, 34, 67} and {90} 
Maximum Pages =113. Therefore, the minimum 
of these cases is 113, which is selected 
as the output.
*/

bool binary_search(int a[], int n, int target, int total){
        int k = 1, sum = 0;
        for(int i=0;i<n;i++){
            if(a[i] > target) return false;
            sum += a[i];
            if(sum > target){
                sum = a[i];
                k++;
            }
        }
        return k<=total;
    }
    
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M) return -1;
        int low = A[N-1], high = 0, res = -1;
        for(int i=0;i<N;i++) high += A[i];
        while(low<=high){
            int mid = low+(high-low)/2;
            if(binary_search(A, N, mid, M)){
                res = mid;
                high = mid-1;
            } else low = mid+1;
        }
        return res;
    }
