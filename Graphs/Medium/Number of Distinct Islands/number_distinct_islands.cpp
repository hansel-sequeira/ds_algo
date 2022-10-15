/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.
*/


//Most important point in this ques deals with storing the path in the set. Why not simple store the path as a string?
//dfs path can be same for islands which do not have same orientation. Eg:
// 1 1
// 1 0   with a path of: " RD"
//and 
// 1 1 
// 0 1 with a path of: " RD".
//Hence we take care of this situation using the coordinates: [(0,0), (0,1), (1,0)] and [(0,0), (0,1), (1,1)]

class Solution {
  private:
  
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis, 
             vector<pair<int,int>>& vec, int r0, int c0){
        int rows = grid.size(), cols = grid[0].size();
        if(r<0 or r>=rows or c<0 or c>=cols or !grid[r][c] or vis[r][c])
            return;
        vis[r][c] = true;
        vec.push_back({r-r0, c-c0});
        dfs(r, c-1, grid, vis, vec, r0, c0);
        dfs(r-1, c, grid, vis, vec, r0, c0);
        dfs(r, c+1, grid, vis, vec, r0, c0);
        dfs(r+1, c, grid, vis, vec, r0, c0);
    }
    
    
  public:

    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int rows = grid.size(), cols = grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] and !vis[i][j]){
                    vector<pair<int,int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    s.insert(vec);
                }
            }
        }
        return s.size();
    }
};
