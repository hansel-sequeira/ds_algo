/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr]
of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/

 bool isPossible(vector<int>& arr, int target, int k){
        int sum = 0;
        for(int i=0;i<k;i++) sum += arr[i];
        if(sum >= target) return true;
        int left = 0, right = k;
        while(right < arr.size()){
            sum -= arr[left++];
            sum += arr[right++];
            if(sum >= target) return true;
        }
        return false;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0, high = nums.size(), res = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(nums, target, mid)){
                cout<<mid<<endl;
                res = mid;
                high = mid-1;
            } else low = mid+1;
        }
        return res;
    }



//LINEAR SOLUTION USING SLIDING WINDOW:


int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = 0, sum = 0;
        int res = INT_MAX;
        while(high < n){
            while(high<n and sum < target){
                sum+= nums[high++];
            }
            while(low<=high and sum>=target){
                res = min(res, high-low);
                sum -= nums[low++];   
            }
        }
        return res == INT_MAX ? 0 : res;
    }
