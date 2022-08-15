/*
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract 
its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
*/

//suboptimal dp solution: n^3

class Solution {
private:
    map<vector<int>, int> m;
    
public:
    
    int isPossible(vector<int>& arr, int low, int high, int required){
        if(required == 0) return 0;
        if(low == high) return (arr[low] == required ? 1 : -1);
        if(arr[low]>required and arr[high] > required) return -1;
        if(m.find({low, high, required}) != m.end()) return m[{low, high, required}];
        //pick from first
        int first = isPossible(arr, low+1, high, required-arr[low]);
        if(first != -1) first++;
        //pick from last
        int last = isPossible(arr, low, high-1, required-arr[high]);
        if(last != -1) last++;
        if(first == -1) return m[{low, high, required}] = last;
        else if(last == -1) return m[{low, high, required}] = first;
        else return m[{low, high, required}] = min(first, last);
    }
    
    int minOperations(vector<int>& nums, int x) {
        //greedy solution just won't work over here!
        return isPossible(nums, 0, nums.size()-1, x);
    }
};






//better solution : nlogn (best case using map) and n (using unordered map)
//sc: O(n)

class Solution {
private:
    map<int,int> left, right;
    
public:
    
    int minOperations(vector<int>& arr, int x) {
        int n = arr.size(), res = INT_MAX, lsum = 0, rsum = 0;
        for(int i=0;i<n;i++){
            lsum += arr[i];
            rsum += arr[n-i-1];
            left[lsum] = i;
            right[rsum] = (n-i-1);
        }
        //first check while going from right to left:
        int target = x;
        for(int i=n-1;i>=0;i--){
            if(arr[i] > target) break;
            target -= arr[i];
            if(target == 0){
                res = min(res, n-i);
                break;
            }
            if(left.find(target) != left.end() and left[target] < i){
                res = min(res, left[target]+1+n-i);
            }
        }        
        
        //now check while going from left to right:
        target = x;
        for(int i=0;i<n;i++){
            if(arr[i] > target) break;
            target -= arr[i];
            if(target == 0){
                res = min(res, i+1);
                break;
            }
            if(right.find(target) != right.end() and right[target]>i){
                res = min(res, i+1+n-right[target]);
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};
