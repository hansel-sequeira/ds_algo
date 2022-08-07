/*
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.
*/

//visualize a valley with peaks and troughs. first & last elt will always be a peak.

int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if((mid==0 || nums[mid]>nums[mid-1]) and (mid==n-1 || nums[mid]>nums[mid+1])) return mid;    
            else if(mid>0 and nums[mid]<nums[mid-1]) high = mid-1;    //if current point is in a decreasing slope, peak lies to the left 
            else low = mid+1;
        }
        return -1;
    }

//the above code handles for n=1 and n=2;
