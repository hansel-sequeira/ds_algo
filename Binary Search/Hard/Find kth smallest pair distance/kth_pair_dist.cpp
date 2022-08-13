/*
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:

Input: nums = [1,1,1], k = 2
Output: 0
Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
*/


int count_occ(vector<int>& arr, int target){
        int res = 0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]-arr[i] <= target) res++;
            }
        }
        return res;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1]-nums[0];
        while(low<high){
            int mid = low+(high-low)/2;
            int count = count_occ(nums, mid);
            if(count >= k) high = mid;
            else low = mid+1;
        }
        return low;
    }

//Bottleneck in the above approach is in count_occ whose tc is n^2. Total tc here is: O(n*n*log(max diff bn any two elts in the array))

//Optimized fn to find no of pairs whose abs diff <= target in O(n) time.
int count_occ(vector<int>& arr, int target){
        int res = 0, right = 0;
        for(int i=0;i<arr.size();i++){
            while(right < arr.size() and arr[right]-arr[i]<=target)
                right++;
            if(right != i) res += (right-i-1);
        }
        return res;
    }
