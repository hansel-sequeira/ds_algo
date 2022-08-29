/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
*/

class Solution {
public:
    
    int compute_val(int r, int c){
        unsigned long long int res = 1;
        for(int i=0;i<c;i++){
            res *= (r-i);
            res /= (i+1);
        }
        return res;
    }
    
    
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int j=0;j<=rowIndex;j++)
            res.push_back(compute_val(rowIndex, j));
        return res;
    }
};
