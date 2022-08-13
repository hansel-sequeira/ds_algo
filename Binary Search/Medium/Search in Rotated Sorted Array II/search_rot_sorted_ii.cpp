/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/

    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > nums[high]){ //left part of mid is sorted
                if(target >= nums[low] and target <= nums[mid])
                    return binary_search(nums.begin()+low, nums.begin()+mid+1, target);
                else low = mid+1;
            } else if(nums[mid] < nums[high]){ //right part is sorted
                 if(target >= nums[mid] and target <= nums[high])
                     return binary_search(nums.begin()+mid, nums.begin()+high+1, target);
                else high = mid-1;
            } else { //ambiguity whether to go to the left or right
                high--;
            }
        } 
        return nums[low] == target;
    }
