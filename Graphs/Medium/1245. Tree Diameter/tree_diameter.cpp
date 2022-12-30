
Given an undirected tree, return its diameter: the number of edges in a longest path in that tree.

The tree is given as an array of edges where edges[i] = [u, v] is a bidirectional edge between nodes u and v. 
Each node has labels in the set {0, 1, ..., edges.length}.


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {

private:
    int res = 0;

public:
    int treeDiameter(vector<vector<int>>& edges) {

        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for(const vector<int>& e: edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        res = 0;
        dfs(g, -1, 0);
        return res;
    }

private:
    int dfs(const vector<vector<int>>& g, int parent, int v){

        int first = 0, second = 0;
        for(int w: g[v])
            if(w != parent){
                int t = 1 + dfs(g, v, w);
                if(t >= first) second = first, first = t;
                else if(t > second) second = t;
            }

        res = max(res, first + second);
        return first;
    }
};


int main() {

    return 0;
}
