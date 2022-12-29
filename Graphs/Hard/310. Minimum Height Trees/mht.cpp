/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two
nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible 
rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


Example 1:


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
*/


//Tc: Bear in mind, that in a undirected acyclic tree (graph alike tree), edges = nodes-1
//Tc: O(n-1) + O(n) + O(n) = O(n)
//sc: O(n)

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        vector<int> heights(n, INT_MAX);
        vector<int> adj[n];
        vector<int> degree(n, 0);
        for(auto it: edges){
            int u = it[0]; int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++; degree[v]++;
        }
        vector<int> res;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i] == 1)
                q.push(i);
        }
        int nodes_trimmed = 0;
        //Kahn's algorithm

        while(!q.empty()){
            vector<int> temp;
            int size = q.size();
            //where 'size' is the number of nodes at a particular radial dist
            while(size--){
                int u = q.front();
                q.pop();
                temp.push_back(u);
                for(int v: adj[u]){
                    if(--degree[v] == 1)
                        q.push(v);
                }
            }
            res = temp;
        }
        return res;
    }
