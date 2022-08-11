/*
On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.

Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.

Return the smallest possible value of D.


1.stations.length will be an integer in range [10, 2000].
2.stations[i] will be an integer in range [0, 10^8].
3.K will be an integer in range [1, 10^6].
4.Answers within 10^-6 of the true value will be accepted as correct.

Example
Example 1:

Input：stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]，K = 9
Output：0.50
Explanation：The distance between adjacent gas stations is 0.50
Example 2:

Input：stations = [3,6,12,19,33,44,67,72,89,95]，K = 2
Output：14.00
Explanation：construction of gas stations at 86 locations
*/

public double minmaxGasDist(int[] stations, int k) {
        // Write your code here
        double start = 0, end = stations[stations.length - 1] - stations[0];
        double eps = 1e-6;
        
        while (start + eps < end) {
            double mid = (start + end) / 2;
            int count = checkStations(stations, mid);
            if (count > k) {
                // minimum stations added is > K
                // so we nned to increase the mid
                start = mid;
            } else {
                // minimum stations added is <= K
                // so we need to narrow the mid
                end = mid;
            }
        }
        return start;
    }
    
    // get the minimum stations count at max distance 'dist'
    private int checkStations(int[] stations, double dist) {
        int count = 0;
        for (int i = 1; i < stations.length; i++) {
            count += (int) ((stations[i] - stations[i - 1]) / dist);
            // for example, 10 / 3, at least put 3 stations
            // to satisfy the condition: max distance is 'dist'
        }
        return count;
    }
