/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int low = 0, high = rows*cols-1;
        while(low<=high){
            int mid = low+(high-low)/2;     
            int row = mid/cols, col = mid%cols;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
