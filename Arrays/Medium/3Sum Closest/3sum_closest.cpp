/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX, n = nums.size();
        for(int i=0;i<n;i++){
            int lb = i+1, ub = n-1;
            while(lb<ub){
                int sum = nums[i] + nums[lb] + nums[ub];
                if(sum == target) return sum;
                if(res==INT_MAX || abs(sum-target) < abs(res-target))
                        res = sum;
                if(sum > target)  ub--;
                else lb++;
            }
        }
        return res;
    }
};
 
