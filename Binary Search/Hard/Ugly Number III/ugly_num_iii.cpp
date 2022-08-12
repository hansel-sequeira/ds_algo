/*
An ugly number is a positive integer that is divisible by a, b, or c.

Given four integers n, a, b, and c, return the nth ugly number.
Example 1:

Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
Example 2:

Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
Example 3:

Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
*/

typedef long long ll;

class Solution {
public:
  
    /*given a range from 1 to n [1,2,3,4,5,6,7 ... n].
    given a midpoint say x, we want to find all nums:1-x divisible by a, b or c.
    if it were find all nums div by just a: x/a. just b: x/b. just c: x/c.
    if it were find all nums div by a,b AND c: x/lcm(a,b,c).
    if it were find all nums div by a, b or c: set intersection problem A + B + C - AUB - BUC - AUC + AUBUC
    or in other words: x/a + x/b + x/c - a/lcm(a,b) {nums div by a AND b!} - a/lcm(b,c) - a/lcm(c,a) + a/lcm(a,b,c)
    
    UNDERSTAND THE DISTINCTION BETWEEN LCM AND GCD:
    LCM(A,B) IS THE LEAST NUMBER DIVISIBLE BY BOTH A AND B. SO IF M IS THE LCM OF A AND B, ALL FURTHER MULTIPLES: 2M, 3M, 4M ... WILL ALSO BE DIVISIBLE.
    SO ASSUMING [1 .. M .. 2M .. 5M ...x] and x<6M is our range. Then x/lcm(a,b) will be giving us 5 -> 5 nums div by both a and b.
    gcd is simply the greatest number that can divide both a and b.
    */
  
  
    //lcm using __gcd():
    ll lcm(ll a, ll b){
        if(a>b) return lcm(b,a);
        return a*(b/__gcd(a,b));
    }
    
    ll gcd(ll a, ll b){
        if(a == 0) return b;
        return gcd(b%a, a);
    }
    
    ll lcm(ll a, ll b){
        if(a>b) return lcm(b,a);
        return (a*b)/gcd(a,b);
    }
    
    int count(int n, ll a, ll b, ll c){
        return n/a + n/b + n/c - n/lcm(a,b) - n/lcm(b,c) - n/lcm(a,c) + n/lcm(a,lcm(b,c)); 
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        int low = min({a,b,c}), high = INT_MAX, res = -1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(count(mid, a, b, c) >= n) high = mid;
            else low = mid+1;
        }
        return low;
    }
};
