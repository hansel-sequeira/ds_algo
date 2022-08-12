/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
*/

int count(vector<vector<int>>& matrix, int target){
        int vals = 0, n = matrix.size();
        for(int i=0;i<n;i++){
            vals += upper_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
        }
        return vals;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); 
        int low = matrix[0][0], high = matrix[n-1][n-1], res = -1;
        
        //case to consider: k=4 and arr: [1,2,3,9,9,9,9].
        //if mid is 5, will our code work? Yes.
   
        while(low<=high){
            int mid = low+(high-low)/2;
            if(count(matrix, mid) >= k){
                res = mid;
                high = mid-1;
            } else low = mid+1;
        }
        return res;
    }
