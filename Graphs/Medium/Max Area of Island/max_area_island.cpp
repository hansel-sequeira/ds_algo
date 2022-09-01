/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four
edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],
[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

//BFS approach:
class Solution {
public:
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int rows = grid.size(), cols = grid[0].size();
        int dir[] = {0,-1,0,1,0};
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                
                if(grid[i][j] == 1){
                    
                    //probe a bfs here
                    q.push({i, j});
                    grid[i][j] = 0;
                    int count = 0;
                    while(!q.empty()){
                        auto it = q.front();
                        q.pop();
                        count++;
                        int x = it.first, y = it.second;
                        for(int i=0;i<4;i++){
                            int new_x = dir[i]+x, new_y = dir[i+1]+y;
                            if(new_x>=0 and new_x<rows and new_y>=0 and new_y<cols and grid[new_x][new_y]){
                                grid[new_x][new_y] = 0;
                                q.push({new_x, new_y});
                            }
                        }
                    }
                    res = max(res, count);
                }
                
            }
        }
        return res;
    }
};

//DFS approach

class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int r, int c){
        int rows = grid.size(), cols = grid[0].size();
        if(r<0 || r>=rows || c<0 || c>=cols) return 0;
        if(grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        return 1+dfs(grid, r-1, c) + dfs(grid, r, c-1) + dfs(grid, r, c+1) + dfs(grid, r+1, c);
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int rows = grid.size(), cols = grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                
                if(grid[i][j] == 1){
                    
                    //probe a dfs here
                    res = max(res, dfs(grid, i, j));
                }
                
            }
        }
        return res;
    }
};
