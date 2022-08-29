/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        long long int count1 = 0, count2 = 0, res1 = LONG_MIN, res2 = LONG_MIN;
        vector<int> res;
        for(int x: nums){
            if(x == res1)
                count1++;
            else if(x == res2)
                count2++;
            else if(count1 == 0){
                count1 = 1;
                res1 = x;
            } else if(count2 == 0){
                count2 = 1;
                res2 = x;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int x: nums){
            if(x == res1) count1++;
            else if(x == res2) count2++;
        }
        if(count1 > nums.size()/3) res.push_back(res1);
        if(count2 > nums.size()/3) res.push_back(res2);
        return res;
    }
};
