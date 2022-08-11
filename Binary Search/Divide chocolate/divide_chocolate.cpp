/*
You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.

You want to share the chocolate with your K friends so you start cutting the chocolate bar into K+1 pieces using K cuts, each piece consists of some consecutive chunks.

Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.

Example 1:
Input: sweetness = [1,2,3,4,5,6,7,8,9], K = 5
Output: 6
Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]

Example 2:
Input: sweetness = [5,6,7,8,9,1,2,3,4], K = 8
Output: 1
Explanation: There is only one way to cut the bar into 9 pieces.

Example 3:
Input: sweetness = [1,2,2,1,2,2,1,2,2], K = 2
Output: 5
Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]

Constraints:
0 <= K < sweetness.length <= 10^4
1 <= sweetness[i] <= 10^5
*/


//take note of this eg: 3 6 7  and the target is 9
//the only way to properly divide this is: (3,6) and (7). But here the minimum is 7 which goes again 

bool isPossible(vector<int>& arr, int target, int k){
  int cuts = 0, sum = 0;
  for(int i=0;i<arr.size();i++){
      sum += arr[i];
      if(sum >= target){
        sum = 0;
        cuts++;
      } 
  }
  return cuts >= k;
}

int solve(vector<int>& arr, int k){
  int low = 0, high = 0, n = arr.size();
  int res = -1;
  for(int x: arr) high = max(high, x);
  while(low<=high){
    int mid = low+(high-low)/2;
    if(isPossible(arr, mid, k+1)){
      res = mid;
      low = mid+1;
    } else high = mid-1;
  }
  return res;
}
