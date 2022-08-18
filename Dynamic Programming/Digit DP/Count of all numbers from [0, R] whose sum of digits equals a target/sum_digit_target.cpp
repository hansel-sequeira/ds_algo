/*

Given a range: [0, R] where R is a huge number (10^18), find the count of all those numbers whose sum is exactly equal to a given x.
*/

/*
Assume a given r: 5 8 3 1 2.  This is a 5 digit number. Now, it is important to understand that the amount of digits from the lb (0 in this case) to the ub
will be the same. So 0 can be written as: 0 0 0 0 0 , 1 as: 0 0 0 0 1 and so on.

Start thinking right from the first digit.
_  -> this can be 0/1/2/3/4 and at max 5.
So if it were 0, we will worry about the remaining (n-1 digits and the sum of which should be x). 
If it were 1, (n-1) digits whose sum should amount to (x-1)
If it were 5, (n-1) digits whose sum should amount to (x-5).

So, dp(n, x) = dp(n-1, x) + dp(n-1, x-1) + ... + dp(n-1, x-5)
Or in short: summation from i=0 to the upper_bound_digit on dp(n-1, x-i).

if the first digit were 0/1/2/3/4, when we're on the second digit, there is no 'tight' constraint. By this we mean, you can place any digit from 0-9.
however if the first digit were the upperbound, then in the second digit, we've a tight constraint (<=8). If the second digit did not hit its upperbound (say it was 6),
then in the third digit we don't have a tight constraint.
So initally, when we're at the first digit, before we call our recursive function, we are in a tight constraint.
*/

int recursive(string& number, int n, int x, bool tight){
  if(x < 0) return 0;
  int ub = number[number.length()-n] - '0';
  if(tight == false) ub = 9;
  if(n == 1){
    if(x<0 or x>=10 or x>=ub) return 0; 
    return 1;
  }
  int count = 0;
  for(int i=0;i<ub;i++){
      count += recursive(number, n-1, x-i, false);
  }
  count += recursive(number, n-1, x-ub, tight);
  return count;
}
