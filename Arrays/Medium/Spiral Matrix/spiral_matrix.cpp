/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size(), cols =matrix[0].size();
        int start_row = 0, end_row = rows-1, start_col = 0, end_col = cols-1;
            
        while(1){
            for(int j = start_col; j<=end_col; j++){
                res.push_back(matrix[start_row][j]);
            }
            start_row++;
            if(start_row > end_row) break;
            for(int i=start_row; i<=end_row; i++){
                res.push_back(matrix[i][end_col]);
            }
            end_col--;
            if(end_col < start_col) break;
            for(int j=end_col; j>=start_col; j--){
                res.push_back(matrix[end_row][j]);
            }
            end_row--;
            if(end_row < start_row) break;
            for(int i=end_row;i>=start_row;i--){
                res.push_back(matrix[i][start_col]);
            }
            start_col++;   
            if(start_col > end_col) break;
        }
        return res;
    }
};
