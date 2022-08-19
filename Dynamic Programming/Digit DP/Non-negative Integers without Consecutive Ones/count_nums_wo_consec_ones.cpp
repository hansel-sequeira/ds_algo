/*

Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones. 

Example 1:

Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
Example 2:

Input: n = 1
Output: 2
Example 3:

Input: n = 2
Output: 3
 

Constraints:

1 <= n <= 109
*/

class Solution {
public:
    
    int number;
    int dp[32][2][2];
    
    int recursive(int bitpos, bool tight, bool previous){
        if(bitpos < 0) return 1;
        if(dp[bitpos][tight][previous] != -1) return dp[bitpos][tight][previous];
        int count = 0, corresponding_val = (number & (1<<bitpos)) ? 1 : 0;
        int ub = tight ? corresponding_val : 1;
        //first allocate 0. No issues
        count += recursive(bitpos-1, tight && (0==corresponding_val), false);
        //now try to allocate 1.
        if(ub == 1 and !previous)
            count += recursive(bitpos-1, tight && corresponding_val, true);
        return dp[bitpos][tight][previous] = count;
    }
    
    int findIntegers(int n) {
        number = n;
        memset(dp, -1, sizeof(dp));
        return recursive(31, true, false);
    }
};
