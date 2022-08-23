/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n-2; i++){
            int j = i+1, k = n-1, target = -nums[i];
            while(j<n and k>i and j<k){
                int sum = nums[j]+nums[k];
                if(sum > target) k--;
                else if(sum < target) j++;
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(j<k and nums[j] == nums[j+1])
                        j++;
                    while(k>i and nums[k] == nums[k-1])
                        k--;
                    j++, k--;
                }
            }
            while(i<n-1 and nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
