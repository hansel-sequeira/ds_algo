///Pre-requisit: 1245. Tree Diameter


class Solution {
private:
    int res;
public:

    int dfs(int u, int parent, vector<int> adj[], vector<char>& char_assn){
        int longest = 0, second_longest = 0;
        for(int v: adj[u]){
            if(v == parent) 
                continue;
            int return_val = dfs(v, u, adj, char_assn);
            if(char_assn[v] == char_assn[u])
                continue;
            if(return_val >= longest){
                second_longest = longest;
                longest = return_val;
            } else if(return_val > second_longest)
                second_longest = return_val;
        }
        res = max(res, longest+second_longest+1);
        return longest+1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        res = 0;
        vector<int> adj[n];
        vector<char> char_assn(n);
        for(int i=1;i<n;i++){
            int u = i; int v = parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            char_assn[i] = s[i];
        }
        dfs(0, -1, adj, char_assn);
        return res;
    }
};
