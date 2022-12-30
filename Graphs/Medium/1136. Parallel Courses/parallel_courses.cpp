int parallelCourses(int n, vector<vector<int>> &prerequisites)
{
    // Write your code here.
    vector<int> adj[n+1];
    vector<int> indegree(n+1, 0);
    for(auto it: prerequisites){        
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }
    queue<int> q;
    int res = 0;
    for(int i=1;i<=n;i++){
        if(!indegree[i])
            q.push(i);
    }
    while(!q.empty()){
        int level_size = q.size();
        while(level_size--){
            int u = q.front();
            q.pop();
            for(int v: adj[u]){
                if(--indegree[v] == 0)
                    q.push(v);
            }   
        }
        res++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i] > 0)
            return -1;
    }
    return (res == 0) ? -1 : res;
}
