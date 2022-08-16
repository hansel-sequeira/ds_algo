
/*
Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
It is guaranteed that there will be a rectangle with a sum no larger than k.
Example 1:
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
Example 2:
Input: matrix = [[2,2,-1]], k = 3
Output: 3
*/


//tc: O(n^6). Avoid!
int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        //horrendously inoptimal solution
        int rows = matrix.size(), cols = matrix[0].size(), result = INT_MIN;
        //4 metrics to probe all rectangles: start_row, start_col, end_col, end_row
        for(int start_row = 0; start_row<rows; start_row++){
            for(int end_row = start_row; end_row<rows; end_row++){
                for(int start_col = 0; start_col<cols; start_col++){
                    for(int end_col = start_col; end_col<cols; end_col++){
                        int sum = 0;
                        for(int i=start_row;i<=end_row;i++){
                            for(int j=start_col;j<=end_col;j++){
                                sum += matrix[i][j];
                            }
                        }
                        if(sum<=k) result = max(result, sum);
                    }
                }
            }
        }
        return result;
    }

 int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = matrix[0].size(), result = INT_MIN;
        for(int left=0;left<cols;left++){
            vector<int> dp(rows, 0);
            for(int right = left; right<cols; right++){
                
                for(int i=0;i<rows;i++)
                    dp[i] += matrix[i][right];
                
                //now basically at this point find the largest sum in the dp subarray <= k
                set<int> s;
                s.insert(0);
                int sum = 0;
                for(int i=0;i<rows;i++){
                    sum += dp[i];
                    int target = sum - k;
                    auto it = s.lower_bound(target);
                    if(it != s.end()) result = max(result, sum - *it);
                    s.insert(sum);
                }
            }
        }
        return result;
    }

//optimal:   cols*cols*(rows + row*log(row))  --> cols*cols*rows*log(rows)
