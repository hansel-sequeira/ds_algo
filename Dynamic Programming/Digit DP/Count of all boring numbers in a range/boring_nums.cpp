/*
Defn of a boring number:  5 7 6 1 2 
5 is at pos 1, 7 at 2, 6 at 3 and so on.
In a boring number, elts at odd position should be odd and even postns to be even.
You're given a range: [L,R] and find the count of all boring nums in this range.
*/

//sol: find for [0,R] - [0,L-1]
//we make a special allocation for an isEven variable for the 'leading zero' case. 0001. This 1 will be at the odd (1) position.


int recursive(string& right, int dig, bool isEven, bool isLeading, bool tight){
  if(dig == 0) return 1;
  if(isEven){
    int ans = 0;
    int ub = (tight == 1 ? right[right.size()-dig]-'0' : 9;
    vector<int> ans = {0, 2, 4, 6, 8};
    for(int x: nums)
    if(x <= ub)
       ans += recursive(right, dig-1, false, false, tight & (x == ub));
    return ans;
              
  } else {
      int ans = 0;
      int ub = (tight == 1 ? right[right.size()-dig]-'0' : 9;
      vector<int> nums = {1, 3, 5, 7, 9}
      if(isLeading) ans += recursive(right, dig-1, false, true, false); 
      for(int x: nums)
         if(x <= ub)
            ans += recursive(right, dig-1, true, false, tight & (x == ub));
       return ans;
  }
}

//don't forget to memoize the above!

//call to the function would then be:
int left, right;
left--;
//to_string() left and right
recursive(right, right.size(), false, true, true) - recursive(left, left.size(), false, true, true);
