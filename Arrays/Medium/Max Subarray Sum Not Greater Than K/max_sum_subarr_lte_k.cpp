/*
Given an array of integers A and an integer k, find a subarray that contains the largest sum, subject to a constraint that the sum is less than k?
*/

//TC: NLOGN

//consider the cummulative sum upto an index j. Now we need to find the cummulative sum upto some index i (i<j) such that the difference is as close to k.
//so basically sum(j) - sum(i) <= k              .... equation 1
//or in other words we need to find a sum(i) s.t:   sum(i) >= sum(j)-k.
//Should sum(i) be as great as possible or as small as possible? It should be as small as possible (look at equation 1)
//so use a set and plug in the cummulative sums at all points. at a certain index j, it should be very easy to find the required sum(i) --> lower_bound
//If the question were to find subarray sum strictly less than K, sum(i) > sum(j)-k .. we would be finding the upper_bound


int result = INT_MAX;
set<int> s;
s.insert(0); //don't forget this!
int sum = 0;
for(int i=0;i<rows;i++){
  sum += dp[i];
  int target = sum - k;
  auto it = s.lower_bound(target);
  if(it != s.end()) result = max(result, sum - *it);
}
return result;
