/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with
its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the
current state of the m x n grid board, return the next state.

Example 1:

Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        int x_dir[] = {0,-1,-1,-1,0,1,1,1};
        int y_dir[] = {-1,-1,0,1,1,1,0,-1};
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                
                int actual = board[i][j]%2;
                int live_nbrs = 0;
                for(int k=0;k<8;k++){
                    int x = x_dir[k]+i, y = y_dir[k]+j;
                    if(x>=0 and x<rows and y>=0 and y<cols and board[x][y]%2)
                        live_nbrs++;
                }
                if(actual == 1){
                    if((live_nbrs>=0 and live_nbrs<=1) || live_nbrs>=4) 
                        board[i][j] += 0;
                    else if(live_nbrs>=2 and live_nbrs<=3)
                        board[i][j] += 2;
                } else {
                    if(live_nbrs == 3)
                        board[i][j] += 4;
                }
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==1 || board[i][j] == 2)
                    board[i][j] = 0;
                else if(board[i][j]==3 || board[i][j]==4)
                    board[i][j] = 1;
            }
        }
    }
};

/*
[0-1] neighbors -> dead
[2-3] neighbors -> lives to the next gen
[4+] neighbors -> dead
dead cell with exactly 3 live neighbors -> live

*/

//change the val st you can get both new and old val   (0,1)


// 0 -> 0 (2)  old: 2%2  new:
// 0 -> 1 (4)  old: 4%2  new: 
    
// 1 -> 0 (1) old: 1%2   new: 
// 1 -> 1 (3) old: 3%2   new: 
