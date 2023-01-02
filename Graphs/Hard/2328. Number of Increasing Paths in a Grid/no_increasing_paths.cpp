class Solution {
public:

    int lis(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int rows = grid.size(), cols = grid[0].size();
        int current = grid[i][j];
        if(dp[i][j] != -1) 
            return dp[i][j];
        unsigned long long int ans = 1;
        int mod = 1e9+7;
        if(j-1>=0 and grid[i][j-1]>current)
            ans += lis(i, j-1, grid, dp)%mod;
        if(i-1>=0 and grid[i-1][j]>current)
            ans += lis(i-1, j, grid, dp)%mod;
        if(j+1<cols and grid[i][j+1]>current)
            ans += lis(i, j+1, grid, dp)%mod;
        if(i+1<rows and grid[i+1][j]>current)
            ans += lis(i+1, j, grid, dp)%mod;
        return dp[i][j] = ans%mod;
    }

    int countPaths(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        unsigned long long int ans = 0; int mod = 1e9+7;
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ans += lis(i, j, grid, dp)%mod;
            }
        }
        return ans%mod;
    }
};
