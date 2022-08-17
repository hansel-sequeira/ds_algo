/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0
*/


//dividend = (quotient)*divisor + remainder
//58 = (11)*5 + 3
//58 = (2^3 + 2^1 + 2^0)*5 + 3
//58 = 2^3*5 + 2^1*5 + 2^0*5 + 3
//keep checking the greatest (2 to the power)*5 which is less than dividend. Say it's 2^x. Ans will then += 2^x and dividend -= 2^x*5. Repeat till dividend>=divisor.

class Solution {
public:
    int divide(int dividend_old, int divisor_old) {
        if(dividend_old == divisor_old) return 1;
        bool isNegative = (dividend_old<0 ^ divisor_old < 0);
        unsigned int dividend = abs(dividend_old), divisor = abs(divisor_old);
        unsigned int ans = 0;
        while(dividend>=divisor){
            int i = 0;
            while(divisor<<(i+1) < dividend){
                i++;
            }
            ans += 1<<i;
            dividend -= divisor<<i;
        }
        if(!isNegative and ans==(1<<31)) return INT_MAX;
        return isNegative ? -ans : ans;
        
        
        //quotient could be: 2^31-1 at max.
        //quotient could be: -2^31 at min.
        //how to handle this min quotient in a 32-bit env? Use unsigned int: -2^32 to 2^32-1
    }
};
