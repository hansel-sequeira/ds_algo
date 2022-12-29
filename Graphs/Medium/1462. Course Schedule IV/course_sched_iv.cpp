void topo_sort(int u, vector<int> adj[], vector<bool>& vis, set<int>& s){
        vis[u] = true;
        for(int v: adj[u]){
            if(!vis[v])
                topo_sort(v, adj, vis, s);
        }
        s.insert(u);
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<int> adj[n];
        for(auto it: edges){
            int u = it[0]; int v = it[1];
            adj[u].push_back(v);
        }
        int q = queries.size();
        for(int i=0;i<q;i++){
            int x = queries[i][0]; int y = queries[i][1];
            set<int> s;
            vector<bool> vis(n, false);
            topo_sort(x, adj, vis, s);
            s.erase(x);
            if(s.find(y) != s.end())
                res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
