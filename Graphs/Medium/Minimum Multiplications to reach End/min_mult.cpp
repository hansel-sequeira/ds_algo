/*
Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the
new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Example 1:

Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30
Example 2:

Input:
arr[] = {3, 4, 65}
start = 7, end = 66175
Output:
4
Explanation:
Step 1: 7*3 = 21 % 100000 = 21 
Step 2: 21*3 = 6 % 100000 = 63 
Step 3: 63*65 = 4095 % 100000 = 4095 
Step 4: 4095*65 = 266175 % 100000 = 66175
*/


//tc: v+e -> 10^5 + (10^5 * N) where N is the total elements in the array

int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        q.push({start, 0});
        vector<int> dist(99999, INT_MAX);
        dist[start] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            if(node == end)
                return steps;
            q.pop();
            for(int x: arr){
                int v = (x*node)%100000;
                if(dist[v] > steps + 1){
                    dist[v] = steps + 1;
                    q.push({v, steps+1});
                }
            }
        }
        return -1;
    }
