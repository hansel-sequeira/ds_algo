/*
Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.


Example 1:

matrix: 
1 2 3
2 4 6
3 6 9

Input: m = 3, n = 3, k = 5
Output: 3
Explanation: The 5th smallest number is 3.
Example 2:

matrix:
1 2 3 
2 4 6

Input: m = 2, n = 3, k = 6
Output: 6
Explanation: The 6th smallest number is 6.
*/


//this fn is nlogn. Overall tc: O(n*logn*log(n*n)). Not very optimal.
int count(int rows, int cols, int target){
        int result = 0;
        for(int i=1;i<=rows;i++){
            int low = 1, high = cols, res = cols+1;
            while(low<=high){
                int mid = low+(high-low)/2;
                int actual = mid*i;
                if(actual > target){
                    res = mid;
                    high = mid-1;
                }
                else low = mid+1;
            }
            result += (res-1);
        }
        return result;
    }
    
    
    //2   4   6   8   10  12
    
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m*n;
        while(low<high){
            int mid = low+(high-low)/2;
            if(count(m,n,mid) >= k) high = mid;
            else low = mid+1;
        }
        return low;
    }


//optimized count fn():
//Remember the pattern to find the upperbound of a target in a matrix given that the matrix is row-wise and col-wise sorted!
//it can be solved in O(n+m) time.

int count(int rows, int cols, int target){
        int result = 0;
        int i = 1, j = cols;
        while(i<=rows and j>=1){
            int actual = i*j;
            if(actual <= target){
                result += j;
                i++;
            } else j--;
        }
        return result;
    }
