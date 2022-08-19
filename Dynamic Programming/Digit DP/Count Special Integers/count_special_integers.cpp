/*
We call a positive integer special if all of its digits are distinct.

Given a positive integer n, return the number of special integers that belong to the interval [1, n].

 

Example 1:

Input: n = 20
Output: 19
Explanation: All the integers from 1 to 20, except 11, are special. Thus, there are 19 special integers.
Example 2:

Input: n = 5
Output: 5
Explanation: All the integers from 1 to 5 are special.
Example 3:

Input: n = 135
Output: 110
Explanation: There are 110 integers from 1 to 135 that are special.
Some of the integers that are not special are: 22, 114, and 131.
 

Constraints:

1 <= n <= 2 * 109
*/


int dp[11][2][1024];
    //why 11? n<=2*10^9 which is 10 digits
    //why 1024 for max mask value? considering we've 10 digits, max bitmask is 1111111111 which equat 
    
    int recursive(string& right, int n, bool tight, int mask){
        if(n == 0) {
            return mask != 0;
        }
        if(dp[n][tight][mask] != -1) return dp[n][tight][mask];
        bool isLeading = true;
        if(mask != 0) isLeading = false;
        int count = 0;
        int ub = (tight == true) ? right[right.size()-n]-'0' : 9;
        if(isLeading){
            count += recursive(right, n-1, false, mask);
            for(int i=1;i<=ub;i++){
                mask = mask | (1<<i);
                count += recursive(right, n-1, tight & (i == ub), mask);  
                mask = mask ^ (1<<i);
            }
        } else {
            for(int i=0;i<=ub;i++){
                if(mask & (1<<i)) continue;
                mask = mask | (1<<i);
                count += recursive(right, n-1, tight & (i==ub), mask);
                mask = mask ^ (1<<i);
            }
        }
        return dp[n][tight][mask] = count;
    }
    
    int countSpecialNumbers(int n) {
        string right = to_string(n);
        memset(dp, -1, sizeof(dp));
        return recursive(right, right.size(), true, 0);
    }
