/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].
Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/

#define iterator vector<int>::iterator

class Solution {
public:
    
    //merge sort variation
    
    int merge_sort(vector<int>& nums, iterator low, iterator high){
        if(high-low <= 1) return 0;
        iterator mid = low+(high-low)/2;
        int res = 0;
        res += merge_sort(nums, low, mid);
        res += merge_sort(nums, mid, high);
        auto i = low, j = mid;
        while(i!=mid and j!=high){
            if(*i/2.0 >  (*j)){
                res += (mid-i);
                j++;
            } else i++;
        }
        inplace_merge(low, mid, high);
        return res;
    }
    
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, begin(nums), end(nums));
    }
};
