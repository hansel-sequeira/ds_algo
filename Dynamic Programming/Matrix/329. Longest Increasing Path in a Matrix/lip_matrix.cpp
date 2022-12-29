int recursive(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int rows = matrix.size(), cols = matrix[0].size();
        if(dp[i][j] != -1)
            return dp[i][j];
        int res = 1; int curr = matrix[i][j];
        if(j-1>=0 and matrix[i][j-1] > curr)
            res = max(res, 1+recursive(i, j-1, matrix, dp));
        if(i-1>=0 and matrix[i-1][j] > curr)
            res =  max(res, 1+recursive(i-1, j, matrix, dp));
        if(j+1<cols and matrix[i][j+1] > curr)
            res = max(res, 1+recursive(i, j+1, matrix, dp));
        if(i+1<rows and matrix[i+1][j] > curr)
            res = max(res, 1+recursive(i+1, j, matrix, dp));
        return dp[i][j] = res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 1;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                res = max(res, recursive(i, j, matrix, dp));
            }
        }
        return res;
    }
