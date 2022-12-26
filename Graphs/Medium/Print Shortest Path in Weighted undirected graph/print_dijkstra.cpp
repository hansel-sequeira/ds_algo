/*
You are given a weighted undirected graph having n+1 vertices numbered from 0 to n and m edges describing there are edges between a to b with some weight, find the
shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.

Example:
Input:
n = 5, m= 6
edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
Output:
1 4 3 5
Explaination:
Shortest path from 1 to n is by the path 1 4 3 5
*/

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> result;
        vector<int> dist(n+1, INT_MAX);
        vector<int> parent(n+1, -1);
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //min-heap
        dist[1] = 0;
        pq.push({0, 1});
        while(!pq.empty()){
            int distance = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for(auto it: adj[u]){
                int v = it.first;
                int wt = it.second;
                if(dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        if(dist[n] == INT_MAX)
            return {-1};
        int node = n;
        while(node != -1){
            result.push_back(node);
            node = parent[node];
        }
        reverse(result.begin(), result.end());
        return result;
    }
