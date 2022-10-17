/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

Example 1:

Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Example 2:

Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
Expected Space Compelxity: O(K)
*/

class Solution{
    
    private:
    void dfs(int u, vector<int> adj[], vector<bool>& vis, stack<char>& s){
        vis[u] = true;
        for(int v: adj[u]){
            if(!vis[v])
                dfs(v, adj, vis, s);
        }
        s.push(u+'a');
    }
    
    
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        string res;
        
        //construct the directed graph
        for(int i=0;i<N-1;i++){
            string u = dict[i], v = dict[i+1];
            int len = min(u.length(), v.length());
            for(int i=0;i<len;i++){
                if(u[i] != v[i]){
                    adj[u[i]-'a'].push_back(v[i]-'a');
                    break;
                }
            }
        }
        
        //now simply perform a topo sort. we'll use dfs
        stack<char> s;
        vector<bool> vis(K, false);
        
        for(int i=0;i<K;i++){
            if(!vis[i])
                dfs(i, adj, vis, s);
        }
        
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
    
        return res;
    }
};
