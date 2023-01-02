class Solution {
private:
    int result;

    void dfs(int u, vector<int>& edges, vector<bool>& vis, vector<bool>& stack, vector<int>& dist){
        vis[u] = true;
        stack[u] = true;
        int v = edges[u];
        if(v != -1){
            if(!vis[v]){
                dist[v] = 1+dist[u];
                dfs(v, edges, vis, stack, dist);
            } else if(vis[v] and stack[v]){
                result = max(result, dist[u]-dist[v]+1);
            }
        }
        stack[u] = false;
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        result = -1;
        vector<bool> vis(n, false);
        vector<bool> stack(n, false);
        vector<int> dist(n, 0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, edges, vis, stack, dist);
            }
        }
        return result;
    }
};
