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

//2 3 4 7 11,  k = 2      missing: {1,5,6,8,9,10}
//we know closest bound index where missing >= k is at 7'position. 7 has 3 missing nos. 4 in turn has just 1. So our search stops at 7.
//It is an absolute certainty that the number will lie between 4 and 7.
//Now use simple math to calculate the number. < . . . . . . . > 7    All the dots (say n) total to 4. (n-k) will give us backward dist to 7.
//so basically the number is 7 - (n-k+1). So for 4th missing number: 7-(4-4+1) = 6
//The math then is: nums[low] - (nums[low]-low-1   - k + 1)    =========> low+k;

//more succinct code:
int findKthPositive(vector<int>& arr, int k) {
        //find whether k belongs to the array or not
        int n = arr.size();
        int max_val = arr[n-1];
        int missing_vals_in_arr = max_val - n;
        if(k > missing_vals_in_arr) return (k - missing_vals_in_arr) + max_val;
        int low = 0, high = arr.size()-1;
        while(low<high){
            int mid = low+(high-low)/2;
            int missing_upto_me = arr[mid]-mid-1;
            if(missing_upto_me < k) low = mid+1;
            else high = mid;
        }
        //return arr[low] - (arr[low]-low-1   -    k + 1);
        return low+k;
    }
