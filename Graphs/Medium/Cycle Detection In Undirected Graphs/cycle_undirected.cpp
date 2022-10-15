/*
Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1
*/


//CHECK FOR ALL COMPONENTS:

//BFS APPROACH:
bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        //bfs
        queue<int> q;
        vector<bool> vis(V, false);
        vector<int> parent(V, -1);
       
        for(int i=0;i<V;i++){
            if(!vis[i]){
                
              q.push(i);
              vis[i] = true;
              while(!q.empty()){
                  auto u = q.front();
                  q.pop();
                  for(int v: adj[u]){
                      if(vis[v] and parent[u]!=v)
                          return true;
                      else if(!vis[v]){
                          vis[v] = true;
                          parent[v] = u;
                          q.push(v);
                      }
                  }
              } 
                
                
            }
        }
        return false;
    }
