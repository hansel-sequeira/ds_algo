class Solution {
private:
    int lastNode;
public:

    const int mod = 1e9+7;

    int dfs(int u, vector<pair<int,int>> adj[], vector<bool>& vis, vector<int>& cost,
    vector<int>& dp){

        if(dp[u] != -1)
            return dp[u];
        vis[u] = true;
        if(u == lastNode){
            vis[u] = false;
            return 1;
        }
        int res = 0;
        for(auto it: adj[u]){
            int v = it.first, w = it.second;
            if(!vis[v] and cost[v] < cost[u]){
                res = (res+dfs(v, adj, vis, cost, dp))%mod;
            }
        }
        vis[u] = false;
        return dp[u] = res%mod;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n];
        lastNode = n-1;
        for(auto it: edges){
            int u = it[0]-1, v = it[1]-1, w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        //Dijkstra
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, n-1});
        dist[n-1] = 0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for(auto it: adj[u]){
                int v = it.first, w = it.second;
                if(dist[v] > cost + w){
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }
        vector<bool> vis(n, false);
        vector<int> dp(n, -1);
        return dfs(0, adj, vis, dist, dp)%mod;
    }
};
