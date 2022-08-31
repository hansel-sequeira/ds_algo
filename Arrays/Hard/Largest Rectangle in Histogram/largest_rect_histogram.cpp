/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

//optimal solution with two passes. Can be improved to just a single pass.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //need nsl and nsr
        int n = heights.size(), res = 0;
        vector<int> nsl(n, 0), nsr(n, 0);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() and heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty()) nsl[i] = -1;
            else nsl[i] = s.top();
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty()) nsr[i] = n;
            else nsr[i] = s.top();
            res = max(res, (nsr[i]-nsl[i]-1)*heights[i]);
            s.push(i);
        }
        return res;
    }
};


//most optimal solution with just a single pass:

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res = 0;
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;i++){
            while(!s.empty() and heights[s.top()]>heights[i])
            {
                int val = s.top();
                s.pop();
                int right_bound = i;
                int left_bound = (s.empty()) ? -1 : s.top();
                res = max(res, (right_bound-left_bound-1)*heights[val]);
            }
            s.push(i);
        }
        while(!s.empty()){
            int val = s.top();
            s.pop();
            int right_bound = n;
            int left_bound = (s.empty()) ? -1 : s.top();
            res = max(res, (right_bound-left_bound-1)*heights[val]);
        }
        return res;
    }
};

//basic intuition is that the stack will always be in sorted (increasing) order. Hence for any new elt x, if s.top() > x, we know that right bound for s.top() is x
//and left bound for s.top() is the next element in the stack. So before popping s.top(), update res.

