/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [1,3,5]
Output: 1
Example 2:

Input: nums = [2,2,2,0,1]
Output: 0
*/

Time complexity: O(n) at the worst and O(logn) at average

int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(nums[mid] < nums[high]) high = mid; //right part is sorted
            else if(nums[mid] > nums[high]) low = mid+1; //left part is sorted
            else {
                //a cursory glance would falsely lead you to believe that you're in the right sorted part. However,
                //this isn't always the case. Eg: 9 3 7 7 7 7 7. Over here, you're in the right sorted part and you want
                //to shift left so it makes sense to do high = mid.
                //But consider this example: 7 7 7 7 7 7 1 2 3 7. Over here, we need to move to thr right, not left.
                //So there is this ambiguity when it comes to nums[mid] = nums[high].
                //The only solution for this is to basically decrement high ptr to have the condition where 
                //nums[new_ptr] < or > nums[mid]
                if(high>0 and nums[high] < nums[high-1]) return nums[high];
                //1 1 1 2 1 1    -> the above condition is a MUST to return the actual pivot at index 4
                else high--;
            }
        }
        return nums[low];
    }
