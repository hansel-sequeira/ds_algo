/*
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.
*/

//This 'peak' element is also called 'bitonic element'.
//Variation: find element in bitonic array. Approach: Find index of bitonic element and then apply BS twice (on lhs and rhs)
//WHY BS IS DONE TWICE? -2 -1 3 5 9 6 4 0 -3.        Here bitonic elt is 9 and to find for 0. 0 fits in bounds of lhs and rhs. ambiguous!
//remember bs done on rhs is for descending sorted array!

//visualize a valley with peaks and troughs. 

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


//even more succinct code:

int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(mid==n-1 || nums[mid] > nums[mid+1]) high = mid;
            else low = mid+1; //careful here! it should be low = mid+1 and NOT low = mid;
            //take : [2,10] for eg. low = 0. now definitely move search space to the right.
        }
        return low;
    }
