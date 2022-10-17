//DFS:

//what is the logic behind pushing the node in the stack before exiting the recursive call?
//assuming the ordering was as such:     3 -> 1 -> 0 -> 2 -> 4
//and the call started with 0. If we pushed first, then the ordering would be: 0,2,4,1,3 which is wrong. What we need to ensure is that regardless of the position
//of the node, all the elements below it and itself are properly arranged. So for 0:  0 2 4 and finally: 3 1 0 2 4

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



//BFS (Kahn's Algorithm)

vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> vis(V, false);
	    vector<int> indeg(V, 0);
	    vector<int> res;
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        for(int x: adj[i])
	            indeg[x]++;
	    }
	    for(int i=0;i<V;i++){
	        if(indeg[i] == 0)
	            q.push(i);
	    }
	    
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        res.push_back(u);
	        vis[u] = true;
	        for(int v: adj[u]){
	            if(!vis[v] and --indeg[v]==0){
	                vis[v] = true;
	                q.push(v);
	            }
	        }
	    }
	    
	    return res;
	}
