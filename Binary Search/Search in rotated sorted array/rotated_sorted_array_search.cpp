/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is:
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
*/

//intuition: pick any random point in the array. It is a GUARANTEE, that either the left or right portion is sorted. If tgt is within the bounds of the sorted part,
//obviously search space is confined to the sorted part, else keep probing over the discrepant part.

    int binary_search(vector<int>& arr, int x, int low, int high){
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid] == x) return mid;
            else if(arr[mid]<x) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target) return mid;
            int left_start = low, left_end = mid;              //LEFT_START = LOW, RIGHT_END = HIGH & NOT [0, N-1]!!
            int right_start = mid+1, right_end = high;        //edge case if n=1. Should work normally otherwise
            //check if left part is sorted
            if(nums[left_start] <= nums[left_end]){
                if(target>=nums[left_start] and target<=nums[left_end])
                    return binary_search(nums, target, left_start, left_end);
                else low = mid+1; //else go to the right part
            } else if(right_start<=right_end) { //else right part is sorted
                if(target>=nums[right_start] and target<=nums[right_end])
                    return binary_search(nums, target, right_start, right_end);
                else high = mid-1; //else go to the left part
            } 
        }
        return -1;
    }
