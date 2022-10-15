/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

class Solution {
public:
    
    bool isSafe(int r, int c, vector<vector<char>>& board,vector<vector<bool>>& vis){
        int rows = board.size(), cols = board[0].size();
        if(r<0 or r>=rows or c<0 or c>=cols or board[r][c]=='X' or vis[r][c])
            return true;
        if(r == 0 or r==rows-1 or c==0 or c==cols-1)
            return false;
        vis[r][c] = true;
        bool res1 = isSafe(r, c-1, board, vis);
        bool res2 = isSafe(r-1, c, board, vis);
        bool res3 = isSafe(r, c+1, board, vis);
        bool res4 = isSafe(r+1, c, board, vis);
        return (res1 and res2 and res3 and res4);
    }
    
    void color(int r, int c, vector<vector<char>>& board){
        int rows = board.size(), cols = board[0].size();
        if(r<0 or r>=rows or c<0 or c>=cols or board[r][c]=='X')
            return;
        board[r][c] = 'X';
        color(r, c-1, board);
        color(r-1, c, board);
        color(r, c+1, board);
        color(r+1, c, board);
    }
    
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& vis){
        int rows = board.size(), cols = board[0].size();
        if(r<0 or r>=rows or c<0 or c>=cols or board[r][c]=='X' or vis[r][c])
            return;
        vis[r][c] = true;
        dfs(r, c-1, board, vis);
        dfs(r-1, c, board, vis);
        dfs(r, c+1, board, vis);
        dfs(r+1, c, board, vis);
    }
    
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        queue<pair<int,int>> q;
        //first find out all the 0-regions
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O' and !vis[i][j]){
                    q.push({i, j});
                    dfs(i, j, board, vis);
                }
            }
        }
        
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                vis[i][j] = false;
    
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            //first check if it's a safe region.
            if(isSafe(r, c, board, vis)){
                //then color it.
                color(r, c, board);
            }
        }
    }
};
