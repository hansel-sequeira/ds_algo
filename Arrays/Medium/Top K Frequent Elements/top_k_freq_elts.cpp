/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/


//nlogn solution using pq
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int x: nums) umap[x]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for(auto it: umap){
            pq.push({it.second, it.first});
        }
        vector<int> res;
        for(int i=0;i<k;i++){
            auto it = pq.top();
            pq.pop();
            res.push_back(it.second);
        }
        return res;
    }
};

//optimal solution using bucket sortclass Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int x: nums) umap[x]++;
        vector<vector<int>> count(nums.size()+1);
        for(auto it: umap){
            count[it.second].push_back(it.first);
        }
        vector<int> res;
        for(int i=nums.size();i>=0;i--){
            if(count[i].empty()) continue;
            for(int x: count[i])
                res.push_back(x);
            if(res.size() == k) break;
        }
        return res;
    }
};
