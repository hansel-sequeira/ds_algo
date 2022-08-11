/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
  
*/



int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int max_val = arr[n-1];
        int missing_vals_in_arr = max_val - n;
        if(k > missing_vals_in_arr) return (k - missing_vals_in_arr) + max_val;
        //if i'm at a position i, the missing vals upto me is: arr[i]-(i+1)
        int low = 0, high = n-1, low_val = 1, high_val = arr[n-1], missing_passed = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid] == mid+1) low = mid+1;
            int missing_vals_upto_me = arr[mid]-mid-1;
            if(missing_vals_upto_me >= k) {
                high = mid-1;
            } else{
                missing_passed = missing_vals_upto_me;
                low_val = arr[mid]+1;
                low = mid+1;
            } 
        }
        return (k-missing_passed+low_val-1);
    }
