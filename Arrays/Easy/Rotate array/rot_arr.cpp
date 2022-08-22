

/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/


void reverse_range(vector<int>& nums, int low, int high){
        while(low<=high){
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++, high--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) k%=n;
        //reverse the first window from [0 to n-k-1]
        int low = 0, high = n-k-1;
        reverse_range(nums, low, high);
        //reverse the second window from [n-k to n-1]
        low = n-k, high = n-1;
        reverse_range(nums, low, high);
        //reverse the whole array
        reverse(nums.begin(), nums.end());
    }
