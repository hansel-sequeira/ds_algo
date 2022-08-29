/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool changed_row = false, changed_col = false;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i == 0 and j == 0 and matrix[i][j] == 0){
                    changed_row = changed_col = true;
                } else if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                    if(i == 0) changed_row = true;
                    else if(j == 0) changed_col = true;
                }
            }
        }
        
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                if(matrix[i][j] == 0 || (i==0 and j==0)) continue;
                else if(i == 0){
                    if(changed_row == true) matrix[i][j] = 0;
                } else if(j == 0){
                    if(changed_col == true) matrix[i][j] = 0;
                } else if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }   
    }
};
