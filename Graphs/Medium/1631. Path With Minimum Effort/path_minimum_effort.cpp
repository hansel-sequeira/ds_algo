/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell 
(row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up,
down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/

//tc: n*m*log(n*m) => edges: (n*m*4) and v = n*m

int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int x = it.second.first; int y = it.second.second;
            int wt = it.first;
            int x_dir[] = {0, -1, 0, 1};
            int y_dir[] = {-1, 0, 1, 0};
            for(int i=0;i<4;i++){
                int new_x = x_dir[i] + x;
                int new_y = y_dir[i] + y;
                if(new_x>=0 and new_x<rows and new_y>=0 and new_y<cols and 
                dist[new_x][new_y] > max(dist[x][y], abs(heights[x][y]-heights[new_x][new_y]))){
                    dist[new_x][new_y] = max(dist[x][y], abs(heights[x][y]-heights[new_x][new_y]));
                    pq.push({dist[new_x][new_y], {new_x, new_y}});
                }
            }
        }
        return dist[rows-1][cols-1];
    }
