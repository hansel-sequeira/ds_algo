/*
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
*/

int lower_bound(vector<int>& arr, int target){
        int low = 0, high = arr.size()-1, res = arr.size();
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid] == target) return mid;
            else if(arr[mid] < target) low = mid+1;
            else {
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }

    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums, target);
        //return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
