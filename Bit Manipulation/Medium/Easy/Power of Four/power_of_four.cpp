/*
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 

Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true
 

Constraints:

-231 <= n <= 231 - 1
*/

//brute force:

bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n<=0 or n%4) return false;
        double res = n;
        while(res>1){
            res/=4.0;
        }
        return res==1;
    }

//cleaner brute force:
bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n<=0) return false;
        while(n>1){
            if(n%4) return false;
            n/=4;
        }
        return n==1;
    }

//optimal soln: O(1) time.
//idea: we know that any power of 4 is also a power of 2.      4^x = 2^(2x)
//we also know that any power of 2, it's bit rep has only one set bit. So obviously, even powers of 4 will have one set bit. But where???

//powers of 2: 1  2 4 8 16  32  64  128 256 ...
//powers of 4: 1  4 16  64  256 ...
//what can we observe??? Powers of 4 will have their set bit only in even positions.

 bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n<=0) return false;
        int right_most = n & ~(n-1);
        if(n > right_most) return false;
        for(int i=0;i<32;i+=2){
            int bit = n & (1<<i);
            if(bit) return true;
        }
        return false;
    }

