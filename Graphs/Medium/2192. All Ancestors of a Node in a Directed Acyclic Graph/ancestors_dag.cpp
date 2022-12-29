void topo_sort(int u, vector<int> adj[], vector<bool>& vis, vector<int>& s){
        vis[u] = true;
        for(int v: adj[u]){
            if(!vis[v]){
                s.push_back(v);
                topo_sort(v, adj, vis, s);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it: edges){
            int u = it[0]; int v = it[1];
            adj[v].push_back(u);
        }
        vector<vector<int>> res(n);
        for(int i=0;i<n;i++){
            vector<int> current_res;
            vector<bool> vis(n, false);
            topo_sort(i, adj, vis, current_res);
            sort(current_res.begin(), current_res.end());    
            res[i] = current_res; 
        }
        return res;
    }
