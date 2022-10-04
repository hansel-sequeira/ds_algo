/*

max subarray with 2 distinct integers

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
 

Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> umap;
        int res = 0, p = 0;
        for(int q=0;q<fruits.size();q++){
            umap[fruits[q]]++;
            if(umap.size() > 2){
                int remove = fruits[p];
                while(--umap[fruits[p]] != 0){
                    p++;
                }
                umap.erase(fruits[p++]);
            }
            res = max(res, q-p+1);
        }
        return res;
    }
};
