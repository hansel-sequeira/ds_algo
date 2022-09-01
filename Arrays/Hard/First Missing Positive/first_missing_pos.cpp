/*
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //the crucial understanding over here is that the missing val could lie only bn [1, len(nums)+1].
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0) 
                nums[i] = 0;
        }
        for(int i=0;i<nums.size();i++){
            int idx = abs(nums[i])-1;
            if(idx >= 0 and idx < nums.size()){
                nums[idx] = (nums[idx] == 0) ? -(nums.size()+2) : ((nums[idx]<0) ? nums[idx] : -nums[idx]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] >= 0) //(i+1) not contained
                return i+1;
        }
        return nums.size() + 1;
    }
};

