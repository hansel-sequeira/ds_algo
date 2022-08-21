/*

You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

 

Example 1:

Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.
Example 2:

Input: arr = [1,7], k = 1
Output: [1,7]
*/



//basic concept here is: [1 2   3   5   7   9]
    //assume we're fixated at 5 and we've a tgt.
    //assume 1/5,  2/5,  3/5   are all <= tgt.
    //now when we're fixated at 7. No need to check for 1/7, 2/7 .. <= tgt. It is obvious!
    //So just compare from the previous point where we left (5 onwards). TC: O(n)
    
    //now for the vals of num and den: we need the greatest fraction possible. So whenever we hit a particular
    //a[i] and a[j] val which is the greates, update the num and den.
    
    vector<int> helper(vector<int>& arr, double target){
        int count = 0, j = 1, n = arr.size();
        int num = arr[0], den = arr[n-1];
        for(int i=0;i<n-1;i++){
            while(j<n and arr[i] > target*arr[j])
                j++;
            count += (n-j);
            if(j!=n and arr[i]*den > arr[j]*num){
                num = arr[i];
                den = arr[j];
            }
        }
        return {count, num, den};
    }
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double low = arr[0]/arr[n-1], high = 1;
        while(low<high){    //no point in having (high-low) > eps because it's a guarantee k exists
            double mid = low+(high-low)/2.0;
            vector<int> val = helper(arr, mid);
            if(val[0] < k) low = mid;
            else if(val[0] > k) high = mid; //be very careful with this condn. Since numbers are prime (unique), don't do: val[0] >= k!!!
            else return {val[1], val[2]};
        }
        return {};
    }
