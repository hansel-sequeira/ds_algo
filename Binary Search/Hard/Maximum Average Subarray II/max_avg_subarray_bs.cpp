/*
Description
Given an array with positive and negative numbers, find the maximum average subarray which length should be greater or equal to given length k.

It's guaranteed that the size of the array is greater or equal to k.

Example
Example 1:

Input:
[1,12,-5,-6,50,3]
3
Output:
15.667
Explanation:
 (-6 + 50 + 3) / 3 = 15.667
Example 2:

Input:
[5]
1
Output:
5.000
*/


//why BS to beginw with? a naive way would be n^2. Since we're not a given a specific target to find, instead to find a "max possible" -> it is an optimization
//problem and hence can only be solved in nlogn.


//suboptimal isPossible(): n^2
bool isPossible(vector<int>& arr, double target, int k){
        int n = arr.size();
        for(int i=0;i<=n-k;i++){
            double sum = 0;
            for(int j=i;j<i+k;j++) sum += arr[j];
            if(sum/k >= target ) return true;
            for(int j = i+k; j<n; j++){
                sum += arr[j];
                if(sum/(j-i+1) >= target) return true;
            }
        }
        return false;
    }

    double maxAverage(vector<int> &nums, int k) {
        // write your code here
        int n = nums.size();
        double low = 0, high = 0;
        for(int i=0;i<n;i++){
            if(nums[i]>0) high += nums[i];
            else low += nums[i];
        }
        while(high-low>1e-4){
            double mid = low+(high-low)/2.0;
            if(isPossible(nums, mid, k)) low = mid;
            else high = mid;
        }
        return low;
    }





//OPTIMAL: isPossible():

bool isPossible(vector<int>& arr, double target, int k){
        int n = arr.size();
        double sum = 0, presum = 0, minpresum = 0;
        for(int i=0;i<k;i++) sum += arr[i]-target;
        if(sum>=0) return true;
        for(int i=k;i<n;i++){
            sum += arr[i]-target;
            presum += arr[i-k]-target;
            minpresum = min(minpresum, presum);
            if(sum-minpresum >= 0) return true;
        }
        return false;
    }
