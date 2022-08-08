/*
Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.


Example 1:

Input:
n = 5
k = 3
arr[] = {5,10,30,20,15}
Output: 35
Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35
*/

bool binary_search(int arr[], int n, long long target, int k){
        long long painters = 1, time = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > target) return false;
            time += arr[i];
            if(time > target){
                painters++;
                time = arr[i];
            }
        }
        return painters<=k;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long low = 0, high = 0;
        for(int i=0;i<n;i++) high += arr[i];
        long long res = high;
        while(low<=high){
            long long mid = low+(high-low)/2;
            if(binary_search(arr, n, mid, k)){
                res = mid;
                high = mid-1;
            } else low = mid+1;
        }
        return res;
    }
