/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

//handle the overflow situation (a + b + c + d)!


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); //don't forget to sort!
        vector<vector<int>> res;
        for(int i=0;i<n-3;i++){
            long long target_3 = target - nums[i];
            for(int j=i+1;j<n-2;j++){
                long long target_2 = target_3 - nums[j];
                int a = j+1, b = n-1;
                while(a<b){
                    long long two_sum = nums[a] + nums[b];
                    if(two_sum < target_2)
                        a++;
                    else if(two_sum > target_2)
                        b--;
                    else {
                        res.push_back({nums[i], nums[j], nums[a], nums[b]});
                        while(a<b and nums[a] == nums[a+1])
                            a++;
                        while(b>a and nums[b] == nums[b-1])
                            b--;
                        a++, b--;
                    }
                }
                while(j<n-1 and nums[j] == nums[j+1])
                    j++;
            }
            while(i<n-1 and nums[i] == nums[i+1])
                i++;
        }  
        return res;
    }
};

