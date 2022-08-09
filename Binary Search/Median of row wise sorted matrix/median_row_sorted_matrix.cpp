/*

Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 

*/



//intuition: if n elements, no of elements <= median value HAS to be ATLEAST (n+1)/2.

int count_lte(vector<vector<int>>& arr, int x){  //returns the upperbound of x
        int result = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i][0] > x) continue;
            result += (upper_bound(arr[i].begin(), arr[i].end(), x) - arr[i].begin());
        }
        return result;
    }


    int median(vector<vector<int>> &matrix, int r, int c){
        // code here          
        int low = matrix[0][0], high = matrix[0][c-1];
        for(int i=1;i<r;i++){
                low = min(low, matrix[i][0]);
                high = max(high, matrix[i][c-1]);
        }
        int res = -1, required_count = (r*c+1)/2;
        while(low<=high){
            int mid = low+(high-low)/2;
            int count = count_lte(matrix, mid); //count the elements <= mid_Val
            if(count < required_count) low = mid+1;
            else {
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
