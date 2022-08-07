/*
Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
constraint for x: [0,2^31-1]
*/

//intuition: sqrt(x) can lie b/n 1 and x/2 -> confined search space, sorted by default & hence can use simple binary search

int mySqrt(int x) {
        if(x < 2) return x;
        int low = 1, high = x/2, res = 1;
        while(low<=high){
            int mid = low+(high-low)/2; 
            if(mid == x/mid) return mid; //can give runtime error if mid = 2^31-1
            else if(mid < x/mid){
                res = mid;
                low = res+1;
            } else high = mid-1;
        }
        return res;
    }

/* Pay special attention: WE ARE NOT DOING MID*MID, because this could lead to overflow.
Hence, to check if mid*mid < x => mid < x/mid.
Another point: what is the proof that sqrt(x) lies between 1 and x/2??
For this, we need (x/2) >= sqrt(x)
or x^2/4 >= x
or x >= 4. So this is only true when x>=4. If x is 3, (answer is 1.7ish, so it won't lie between 1 and 1.5). Considering this question asks to truncate decimal places,
it won't matter. But do consider this edge case when decimal values come into the picture.
