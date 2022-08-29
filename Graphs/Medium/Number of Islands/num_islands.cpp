/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dir[] = {0,-1,0,1,0};
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '1'){
                    
                    count++;
                    grid[i][j] = '#';
                    q.push({i,j});
                    
                    while(!q.empty()){
                        auto it = q.front();
                        q.pop();
                        int x = it.first, y = it.second;
                        for(int i=0;i<4;i++){
                            int new_x = dir[i]+x, new_y = dir[i+1]+y;
                            if(new_x>=0 and new_x<rows and new_y>=0 and new_y<cols and 
                                grid[new_x][new_y]=='1'){
                                grid[new_x][new_y] = '#';
                                q.push({new_x, new_y});
                            }
                        }
                    }
                    
                }
            }   
        }
        return count;
    }
};


//a dfs solution:
class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        int rows = grid.size(), cols = grid[0].size();
        if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j]=='0') return;
        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        dfs(grid, i+1, j);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
