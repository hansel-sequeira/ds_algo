/*Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.

 

Example 1:

Input: n = 20
Output: 1
Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
Example 2:

Input: n = 100
Output: 10
Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
Example 3:

Input: n = 1000
Output: 262
 

Constraints:

1 <= n <= 10^9


*/

class Solution {
public:
    
    int dp[11][2][1024];
    //why 11? n<=2*10^9 which is 10 digits
    //why 1024 for max mask value? considering we've 10 digits, max bitmask is 1111111111 which equates to 1023
    
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
    
    int numDupDigitsAtMostN(int n) {
        return n - countSpecialNumbers(n);
    }
};

//TC: O(log(r)) log r (base 10) = n which is the number of digits
