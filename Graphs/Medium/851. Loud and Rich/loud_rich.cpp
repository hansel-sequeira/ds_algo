void topo_sort(int u, vector<int> adj[], vector<bool>& vis, queue<int>& q){
        vis[u] = true;
        for(int v: adj[u]){
            if(!vis[v])
                topo_sort(v, adj, vis, q);
        }
        q.push(u);
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        //just identify all those nodes which are topologically superior to a node
        int n = quiet.size();
        vector<int> adj[n];
        for(auto it: richer){
            int u = it[0]; int v = it[1];
            adj[v].push_back(u);
        }
        vector<int> res(n, 0);
        for(int i=0;i<n;i++)
            res[i] = i;

        //perform topo_sort for each node
        for(int i=0;i<n;i++){
            vector<bool> vis(n, false);
            queue<int> q;
            topo_sort(i, adj, vis, q);
            int min_so_far = i;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(quiet[min_so_far] > quiet[u])
                    min_so_far = u;
            }
            res[i] = min_so_far;
        }
        return res;
    }
