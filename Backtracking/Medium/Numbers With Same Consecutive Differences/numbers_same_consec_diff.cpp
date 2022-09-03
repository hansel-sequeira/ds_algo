/*
Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.

Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.

You may return the answer in any order.

 

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Constraints:

2 <= n <= 9
0 <= k <= 9
*/

class Solution {
public:
    
    vector<int> res;
    
    void recursive(int num, int prev, int n, int k){
        if(n == 0){
            res.push_back(num);
            return;
        }
        for(int i=0;i<=9;i++){
            if(abs(i-prev)==k){
                recursive(num*10+i, i, n-1, k);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            recursive(i, i, n-1, k);
        }
        return res;
    }
};


//optimal soln:

class Solution {
public:
    
    vector<int> res;
    
    void recursive(int num, int n, int k){
        if(n == 0){
            res.push_back(num);
            return;
        }
        int last_dig = num%10;
        if(last_dig+k<=9)
            recursive(num*10+(last_dig+k), n-1, k);
        if(k!=0 and last_dig-k>=0) //don't forget to check k!=0. Why?
            recursive(num*10+(last_dig-k), n-1, k);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            recursive(i, n-1, k);
        }
        return res;
    }
};
