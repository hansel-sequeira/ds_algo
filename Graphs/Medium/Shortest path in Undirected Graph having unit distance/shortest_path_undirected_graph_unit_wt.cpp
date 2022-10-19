/*
You are given an Undirected Graph having unit weight, Find the shortest path from src(0) to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Example:

Input:
n = 9, m= 10
edges=[[0,1],[0,3],[3,4],[4 ,5]
,[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4
*/

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> res(N, -1);
        vector<bool> vis(N, false);
        queue<int> q;
        q.push(src);
        vis[src] = true;
        res[src] = 0;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: adj[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                    res[v] = res[u] + 1;
                }
            }
        }

        return res;
    }
