/*
There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the
matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells,
where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water
(i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row
and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

 

Example 1:


Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.
Example 2:


Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.
Example 3:


Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.
*/



bool isPossible(vector<vector<int>>& cells, int rows, int cols, int days){
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        for(int i=0;i<days;i++){
            vis[cells[i][0]-1][cells[i][1]-1] = true;
        }
        queue<pair<int,int>> q;
        for(int j=0;j<cols;j++){
            if(!vis[0][j]) q.push({0, j});
        }
        int dir[] = {0, 1, 0, -1, 0};
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            if(x == rows-1) return true;
            for(int i=0;i<4;i++){
                int r = x+dir[i], c = y+dir[i+1];
                if(r>=0 and r<rows and c>=0 and c<cols and !vis[r][c]){
                    vis[r][c] = true;
                    q.push({r, c});
                }
            }
        }
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size(), result = 0;
        int low = 1, high = n;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(cells, row, col, mid)){
                result = mid;
                low = mid+1;
            } else high = mid-1;
        }
        return result;
    }


/*ime: O(row*col * log(row*col)), where row * col <= 2*10^4 is length of the grid.
Binary search in range [1...row*col] take log(row*col).
Each binary search, we need to bfs in the grid to check if it's good or not, bfs takes O(E+V), where E=4*V (because each cells have up to 4 neighbors), 
so time complexity is O(E+V) = O(4V+V) = O(5V) ~ O(row*col).So total time complexity is O(row*col * log(row*col))
Space: O(row*col)*/
//observation: in order to find out if you can reach from src to dest and there are obstacles, can use bfs.
