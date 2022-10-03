/*
Given an array arr[], the task is to find the elements of a contiguous subarray of numbers which has the largest sum.

Examples:

Input: arr = [-2, -3, 4, -1, -2, 1, 5, -3]
Output: [4, -1, -2, 1, 5]
Explanation: 
In the above input the maximum contiguous subarray sum is 7 and the elements of the subarray are [4, -1, -2, 1, 5]

Input: arr = [-2, -5, 6, -2, -3, 1, 5, -6] 
Output: [6, -2, -3, 1, 5] 
Explanation: 
In the above input the maximum contiguous subarray sum is 7 and the elements 
of the subarray are [6, -2, -3, 1, 5]
*/

//can easily be done with O(N) space. Let's try doing it in O(1) space.
//in normal kadane, res = max(res + nums[i], nums[i]).
//intuitively, if nums[i] is the greatest point so far, the starting point of the printing will be that index. else it won't change.

#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& arr){
  int n = arr.size(), sum = arr[0], res = arr[0];
  int idx = 0;
  vector<int> vals;
  for(int i=1;i<n;i++){
    sum = max(sum+arr[i], arr[i]);
    if(res < sum){
        res = sum;
        idx = i;
    } 
  }
  
  while(res!=0){
    	vals.push_back(arr[idx]);
    	res -= arr[idx--];
    }
  for(int x: vals)
    cout<<x<<" ";

}

int main() {
        vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
        print(arr);
        return 0;
}
