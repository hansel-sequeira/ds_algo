/*
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= n <= 2000
0 <= dislikes.length <= 104
dislikes[i].length == 2
1 <= dislikes[i][j] <= n
ai < bi
All the pairs of dislikes are unique.
*/

class Solution {
    
private:
    bool dfs(int u, vector<int>& colors, vector<int> adj[]){
        for(int v: adj[u]){
            if(colors[v] == colors[u])
                return false;
            else if(colors[v]==-1){
                colors[v] = 1-colors[u];
                if(!dfs(v, colors, adj))
                    return false;
            }
        }
        return true;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n];
        for(auto vec: dislikes){
            int u = vec[0]-1, v = vec[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        //adjacency list created. Now simply apply normal bipartite check.
        vector<int> colors(n, -1);
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                colors[i] = 0;
                if(!dfs(i, colors, adj))
                    return false;
            }
        }
        return true;
    }
};
