/*
You are given an array points containing the coordinates of points on a 2D plane, sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. You are also given an integer k.

Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.

It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.

 

Example 1:

Input: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
Output: 4
Explanation: The first two points satisfy the condition |xi - xj| <= 1 and if we calculate the equation we get 3 + 0 + |1 - 2| = 4. Third and fourth points also satisfy the condition and give a value of 10 + -10 + |5 - 6| = 1.
No other pairs satisfy the condition, so we return the max of 4 and 1.
Example 2:

Input: points = [[0,0],[3,0],[9,2]], k = 3
Output: 3
Explanation: Only the first two points have an absolute difference of 3 or less in the x-values, and give the value of 0 + 0 + |0 - 3| = 3.
 

Constraints:

2 <= points.length <= 105
points[i].length == 2
-108 <= xi, yi <= 108
0 <= k <= 2 * 108
xi < xj for all 1 <= i < j <= points.length
xi form a strictly increasing sequence.
*/

class Solution {
public:

    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        /*
            yi + yj + (xi-xj)
            (xi+yi) + (yj-xj)   -> we want i>j (which it already is) and xi-xj<=k
        */
        int res = INT_MIN;
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
            auto it = points[i];
            while(!pq.empty() and it[0]-pq.top().second>k) 
                pq.pop();
            if(!pq.empty())
                res = max(res, it[0]+it[1]+pq.top().first);
            pq.push({it[1]-it[0], it[0]});
        }
        return res;
    }
};


//TC of the above solution is nlogn

//can also be done in linear time using a deque

class Solution {
public:

    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        /*
            yi + yj + (xi-xj)
            (xi+yi) + (yj-xj)   -> we want i>j (which it already is) and xi-xj<=k
        */
        int res = INT_MIN;
        deque<pair<int,int>> dq;
        for(auto it: points){
            int xi = it[0], yi = it[1];
            while(!dq.empty() and xi-dq.front().second > k)
                dq.pop_front();
            if(!dq.empty())
                res = max(res, it[0]+it[1]+dq.front().first);
            while(!dq.empty() and dq.back().first < (yi-xi))
                dq.pop_back();
            dq.push_back({yi-xi, xi});
        }
        return res;
    }
};
