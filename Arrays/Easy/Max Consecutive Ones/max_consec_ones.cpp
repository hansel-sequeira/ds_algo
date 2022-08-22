/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

int findMaxConsecutiveOnes(vector<int>& nums) {
        //trivial flow problem.
        int res = 0, flow = 0;
        for(int x: nums){
            if(x == 0) flow = 0;
            else {
                flow++;
                res = max(res, flow);
            }
        }
        return res;
    }


int findMaxConsecutiveOnes(vector<int>& nums) {
        //sliding window approach.
        int res = 0, i = 0;
        while(i<nums.size()){
            int j = i;
            while(j<nums.size() and nums[j] == 1)
                j++;
            res = max(res, j-i);
            i = j+1;
        }
        return res;
    }
