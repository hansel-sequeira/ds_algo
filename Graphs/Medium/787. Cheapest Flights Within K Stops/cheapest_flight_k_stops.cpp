/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from 
city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/

//Tc: in actuality -> bfs up to level k.   (v+e)

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k += 1;
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            int src = flights[i][0]; int dest = flights[i][1]; int cost = flights[i][2];
            adj[src].push_back({dest, cost});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n, INT_MAX);
        q.push({src, {0, 0}});
        dist[src] = 0;
        while(!q.empty()){
            int u = q.front().first;
            int cost = q.front().second.first;
            int k_accrued = q.front().second.second;
            q.pop();
            for(auto it: adj[u]){
                int v = it.first; int w = it.second;
                if(dist[v]>cost+w and k_accrued+1<=k){
                    dist[v] = cost+w;
                    q.push({v, {dist[v], k_accrued+1}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
