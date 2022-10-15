/*
Using DFS: (KEEPING track of nodes in the current recursive stack)
*/
bool dfs(int u, vector<int> adj[], vector<bool>& vis, vector<bool>& recursive_stack){
        vis[u] = true;
        recursive_stack[u] = true;
        for(int x: adj[u]){
            if(vis[x] and recursive_stack[x])
                return true;
            else if(!vis[x]){
                vis[x] = true;
                if(dfs(x, adj, vis, recursive_stack))
                    return true;
            }
        }
        recursive_stack[u] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> recursive_stack(V, false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, recursive_stack))
                    return true;
            }
        }
        return false;
    }
