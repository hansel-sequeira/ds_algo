/*
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.


Example 1:
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.
*/

bool isPossible(vector<int>& arr, int balls, int target){
        int placed = 1, prev_position = arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-prev_position >= target){
                prev_position = arr[i];
                placed++;
            }
        }
        return placed >= balls;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n = position.size(), res = -1;
        sort(position.begin(), position.end());
        int low = 1, high = position[n-1]-position[0];
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(position, m, mid)){
                res = mid;
                low = mid+1;
            } else high = mid-1;
        }
        return res;
    }
