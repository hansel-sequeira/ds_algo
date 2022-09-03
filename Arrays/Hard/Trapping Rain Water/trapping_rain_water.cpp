/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being
trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/


//not optimal soln: n time, n space
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), result = 0;
        vector<int> gr_arr(n, -1);
        int gl = 0, gr = n-1;
        for(int i=n-2;i>=0;i--){
            if(height[i]<=height[gr])
                gr_arr[i] = gr;
            else gr = i;
        }
        for(int i=1;i<n-1;i++){
            if(height[gl]<height[i])
                gl = i;
            else if(gr_arr[i] == -1)
                continue;
            else result += min(height[gl], height[gr_arr[i]])-height[i];
        }
        return result;
    }
};


//optimal solution using two pointer approach.
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), result = 0;
        int left = 0, right = n-1;
        int leftmax = 0, rightmax = 0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(leftmax<=height[left])
                    leftmax = height[left];
                else result += leftmax-height[left];
                left++;
            } else {
                if(rightmax<=height[right])
                    rightmax = height[right];
                else result += rightmax-height[right];
                right--;
            }
        }
        return result;
    }
};
