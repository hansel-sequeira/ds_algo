//DFS:

void dfs(int u, vector<bool>&  vis, vector<int>& res, vector<int> adj[]){
	    vis[u] = true;
	    for(int x: adj[u]){
	        if(!vis[x])
	            dfs(x, vis, res, adj);
	    }
	    res.push_back(u);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> res;
	    vector<bool> vis(V, false);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i, vis, res, adj);
	        }
	    }
	    reverse(res.begin(), res.end());
	    return res;
	}
