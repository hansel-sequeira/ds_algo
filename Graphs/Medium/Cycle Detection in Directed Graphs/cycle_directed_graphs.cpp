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



//BFS (Using Kahn's algorithm for topological sorting)

bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V, 0);
        vector<bool> vis(V, false);
        queue<int> q;
        for(int i=0;i<V;i++){
            for(int j: adj[i])
                indegree[j]++;
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: adj[u]){
                if(!vis[v] and --indegree[v]==0){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i] != 0)
                return true;
        }
        return false;
    }
