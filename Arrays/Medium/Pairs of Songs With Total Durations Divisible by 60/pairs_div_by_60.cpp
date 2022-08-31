/*
You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with
(time[i] + time[j]) % 60 == 0.

 

Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
Example 2:

Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //relate this question to 'find all pairs with a particular sum!'
        //another crucial point: no negative nums. So if you're at x where x>tgt. You CAN'T find a y st (x+y)=target
        //similarly, if you're at x where x<=tgt, you NEED to find a y>x. (in short, find target-x).
        int count = 0, n = time.size();
        vector<int> map(60, 0);
        for(int i=n-1;i>=0;i--){
            if(time[i]%60 == 0)
                count += map[0];
            else count += map[60-time[i]%60];
            map[time[i]%60]++;
        }
        return count;
    }
};


