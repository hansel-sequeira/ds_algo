/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/

//BFS approach. TC: N^2
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //bfs
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        if(grid[0][0])
            return -1;
        queue<pair< pair<int,int> , int>> q;
        q.push({{0,0}, 1});
        vis[0][0] = true;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;
            int dist = it.second;
            if(x==n-1 and y==n-1)
                return dist;
            //probe all 8 directions
            int x_dir[] = {0, -1, -1, -1, 0, 1, 1, 1};
            int y_dir[] = {-1, -1, 0, 1, 1, 1, 0, -1};
            for(int i=0;i<8;i++){
                int new_x = x_dir[i] + x;
                int new_y = y_dir[i] + y;
                if(new_x>=0 and new_x<n and new_y>=0 and new_y<n and !grid[new_x][new_y] and
                    !vis[new_x][new_y]){
                        q.push({{new_x, new_y}, dist+1});
                        vis[new_x][new_y] = true;
                    }
            }
        }
        return -1;
    }
