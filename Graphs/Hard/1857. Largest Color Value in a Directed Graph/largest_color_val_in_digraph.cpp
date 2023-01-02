class Solution {
private:
    int res;
public:

    void dfs(int u, vector<int> adj[], vector<vector<int>>& map, vector<bool>& vis, vector<char>& color){
        vis[u] = true;
        int ans = 0;
        for(int v: adj[u]){
            if(!vis[v]) 
               dfs(v, adj, map, vis, color);
            for(int i=0;i<26;i++)
               map[u][i] = max(map[u][i], map[v][i]);
        }
        map[u][color[u]-'a']++;
        for(int i=0;i<26;i++)
           ans = max(ans, map[u][i]);
        res = max(res, ans);
    }

    bool cycle_dfs(int u, vector<int> adj[], vector<bool>& vis, vector<bool>& s){
        vis[u] = true;
        s[u] = true;
        for(int v: adj[u]){
            if(!vis[v] and cycle_dfs(v, adj, vis, s))
                return true;
            else if(vis[v] and s[v])
                return true;
        }
        return s[u] = false;
    }

    bool cycleExists(vector<int> adj[], int n){
        vector<bool> vis(n, false);
        vector<bool> s(n, false);
        for(int i=0;i<n;i++){
            if(!vis[i] and cycle_dfs(i, adj, vis, s))
                return true;
        }
        return false;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        res = 0;
        vector<int> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        if(cycleExists(adj, n))
            return -1;
        vector<char> color_assn(n);
        vector<vector<int>> map(n, vector<int>(26, 0));
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++){
            color_assn[i] = colors[i];
        }
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i, adj, map, vis, color_assn);
        }
        return res;
    }
};
