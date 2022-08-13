/*
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9
Example 3:

Input: nums = [1,4,4], m = 3
Output: 4
*/

bool isPossible(vector<int>& arr, int subarrays, int max_sum){
        int sum = 0, sub_count = 1;
        for(int i=0;i<arr.size();i++){
            if(arr[i] > max_sum) return false;
            if(sum + arr[i] > max_sum){
                sub_count++;
                sum = arr[i];
            } else sum += arr[i];
        }
        return sub_count <= subarrays;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int low = 0, high = 0, res = -1;
        for(int x: nums) high += x;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(nums, m, mid)){
                res = mid;
                high = mid-1;
            } else low = mid+1;
        }
        return res;
    }
