/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

*/

intuition: naive O(n) => simple xor
optimal: logn

int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1, n = nums.size();
        while(low<=high){
            int mid = low+(high-low)/2;
            if((mid == 0 || nums[mid] != nums[mid-1]) and (mid == n-1 || nums[mid] != nums[mid+1])) return nums[mid];
            else if(mid%2){
                if(nums[mid] == nums[mid-1]){ //single elt lies on the right
                    low = mid+1;
                } else { //single elt lies on the left
                    high = mid-1;
                }
            } else {
                if(mid>0 and nums[mid] == nums[mid-1]){ //single elt lies on the left
                    high = mid-2;
                } else { //single elt lies on the right
                    low = mid+2;
                }
            }
        }
        return -1;
    }
