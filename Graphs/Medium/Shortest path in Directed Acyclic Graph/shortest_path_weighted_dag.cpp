/*
Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i, 0<=i

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

 

Example:

Input:
n = 6, m= 7
edge=[[0,1,2],[0,4,1],[4,5,4]
,[4,2,2],[1,2,3],[2,3,6],[5,3,1]]

Output:
0 2 3 6 1 5
*/

//The most efficient approach to this problem uses Topological Sorting (V+E)

private:
    void dfs(int u, vector<bool>& vis, stack<int>& s, vector<pair<int,int>> adj[]){
        vis[u] = true;
        for(auto vec: adj[u]){
            if(!vis[vec.first])
                dfs(vec.first, vis, s, adj);
        }
        s.push(u);
    }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        stack<int> s;
        vector<int> res(N, INT_MAX);
        vector<pair<int,int>> adj[N];
        
        for(int i=0;i<M;i++){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        res[0] = 0;
        vector<bool> vis(N, false);
        for(int i=0;i<N;i++){
            if(!vis[i])
                dfs(i, vis, s, adj);
        }
        
        while(!s.empty()){
            int u = s.top();
            s.pop();
            if(res[u] == INT_MAX){
                res[u] = -1;
                continue;
            }
            for(auto it: adj[u]){
                int v = it.first, wt = it.second;
                if(res[u] + wt < res[v])
                    res[v] = res[u] + wt;
            }
        }
        return res;
    }
