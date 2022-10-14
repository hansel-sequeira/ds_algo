/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

class Solution {
private:
    int x_dir[4] = {0, -1, 0, 1};
    int y_dir[4] = {-1, 0, 1, 0};
    
public:
    
    bool freshLeft(vector<vector<int>>& grid){
        int rows = grid.size(), cols = grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1)
                    return true;
            }
        }
        return false;
    }
    
    //this function rots one layer of oranges
    bool rot(vector<vector<int>>& grid, queue<pair<int,int>>& q){
        int rows = grid.size(), cols = grid[0].size();
        int size = q.size();
        bool madeRots = false;
        for(int i=0;i<size;i++){
            auto [r, c] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int new_x = x_dir[i]+r;
                int new_y = y_dir[i]+c;
                if(new_x>=0 and new_x<rows and new_y>=0 and new_y<cols and grid[new_x][new_y]==1){
                    grid[new_x][new_y] = 2;
                    madeRots = true;
                    q.push({new_x, new_y});
                }
            }
        }
        return madeRots;
    }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int timer = 0;
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        while(!q.empty()){
            if(rot(grid, q))
                timer++;
            else break;
        }
        return freshLeft(grid) ? -1 : timer;
    }
};
