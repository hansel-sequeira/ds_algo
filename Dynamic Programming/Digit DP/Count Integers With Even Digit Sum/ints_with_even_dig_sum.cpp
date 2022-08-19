/*
Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.

The digit sum of a positive integer is the sum of all its digits.


Example 1:

Input: num = 4
Output: 2
Explanation:
The only integers less than or equal to 4 whose digit sums are even are 2 and 4.    
Example 2:

Input: num = 30
Output: 14
Explanation:
The 14 integers less than or equal to 30 whose digit sums are even are
2, 4, 6, 8, 11, 13, 15, 17, 19, 20, 22, 24, 26, and 28.
*/

int dp[5][2][2];
    
    int recursive(string& right, int n, bool tight, bool isEven){
        if(n == 0) return isEven;
        if(dp[n][tight][isEven] != -1) return dp[n][tight][isEven];
        int ub = tight ? right[right.size()-n]-'0' : 9;
        int count = 0;
        for(int i=0;i<=ub;i++){
            if(i > ub) break;
            bool currEven = (i%2 == 0);
            count += recursive(right, n-1, tight && (i == ub), isEven == currEven);
        }
        return dp[n][tight][isEven] = count;
    }
    
    int countEven(int num) {
        string right = to_string(num);
        memset(dp, -1, sizeof(dp));
        return recursive(right, right.size(), true, true)-1;
    }
