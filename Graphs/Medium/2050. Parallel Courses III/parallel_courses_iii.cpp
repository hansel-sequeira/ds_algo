int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n+1];
        vector<int> indegree(n+1, 0);
        for(auto it: relations){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        vector<int> cost(n+1);
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(!indegree[i]){
                q.push(i);
                cost[i] = time[i-1];
            }
        }
        int res = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v: adj[u]){
                cost[v] = max(cost[v], cost[u]+time[v-1]);
                if(--indegree[v] == 0)
                    q.push(v);
            }
        }
        res = cost[1];
        for(int i=1;i<=n;i++)
            res = max(res, cost[i]);
        return res;
    }
