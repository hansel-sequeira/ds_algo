class Solution {
public:

    void topo_sort(int u, vector<int> adj[], vector<bool>& vis, stack<int>& s){
        vis[u] = true;
        for(int v: adj[u]){
            if(!vis[v])
                topo_sort(v, adj, vis, s);
        }
        s.push(u);
    }

    bool cycleExists(int u, vector<int> adj[], vector<bool>& vis, vector<bool>& s){
        vis[u] = true;
        s[u] = true;
        for(int v: adj[u]){
            if(!vis[v]){
                if(cycleExists(v, adj, vis, s))
                    return true;
            } else if(vis[v] and s[v])
                return true;
        }
        s[u] = false; 
        return false;
    }

    vector<vector<int>> buildMatrix(int n, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        vector<int> row_adj[n], col_adj[n];
        for(int i=0;i<rowConditions.size();i++){
            int u = rowConditions[i][0]-1; int v = rowConditions[i][1]-1;
            row_adj[u].push_back(v);
        }
        for(int i=0;i<colConditions.size();i++){
            int u = colConditions[i][0]-1; int v = colConditions[i][1]-1;
            col_adj[u].push_back(v);
        }
        vector<bool> vis(n, false);
        vector<bool> s(n, false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(cycleExists(i, row_adj, vis, s))
                    return {};
            }
        }
        fill(vis.begin(), vis.end(), false);
        fill(s.begin(), s.end(), false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(cycleExists(i, col_adj, vis, s))
                    return {};
            }
        }

        //now ready to construct the new matrix
        map<int, pair<int,int>> m;
        //topo_sort for row
        fill(vis.begin(), vis.end(), false);
        stack<int> row_sort;
        for(int i=0;i<n;i++){
            if(!vis[i])
                topo_sort(i, row_adj, vis, row_sort);
        }
        //topo_sort for column
        fill(vis.begin(), vis.end(), false);
        stack<int> col_sort;
        for(int i=0;i<n;i++){
            if(!vis[i])
                topo_sort(i, col_adj, vis, col_sort);
        }

        int x = 0;
        while(!row_sort.empty()){
            int u = row_sort.top();
            row_sort.pop();
            m[u].first = x;
            ++x;
        }

        int y = 0;
        while(!col_sort.empty()){
            int u = col_sort.top();
            col_sort.pop();
            m[u].second = y;
            ++y;
        }

        for(int i=0;i<n;i++){
            auto [x, y] = m[i];
            result[x][y] = (i+1);
        }

        return result;
    }
};
