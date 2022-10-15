/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/

class Solution {
private:
    int x_dir[4] = {0, -1, 0, 1};
    int y_dir[4] = {-1, 0, 1, 0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, 0));
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j] == 0)
                    q.push({i, j});
            }
        }
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            vis[r][c] = true;
            //traverse all 4 dirns (dist: 1) and place in queue whilst updating dist
            for(int dir=0;dir<4;dir++){
                int new_x = x_dir[dir] + r;
                int new_y = y_dir[dir] + c;
                if(new_x>=0 and new_x<rows and new_y>=0 and new_y<cols and !vis[new_x][new_y] and
                    mat[new_x][new_y]){
                    vis[new_x][new_y] = true;
                    dist[new_x][new_y] = dist[r][c] + 1;
                    q.push({new_x, new_y});
                }
            }
        }
        return dist;
    }
};
