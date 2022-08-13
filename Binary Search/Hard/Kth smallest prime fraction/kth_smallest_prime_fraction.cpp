/*

You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

 

Example 1:

Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.
Example 2:

Input: arr = [1,7], k = 1
Output: [1,7]
*/


int count(vector<int>& arr, double target){
        int low = 0, res = 0, n = arr.size();
        for(int i=0;i<n;i++){
            while(low<n and (double)arr[i]/(double)arr[low]>target)
                low++;
            res += (n-low);
        }
        return res;
    }
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double low = 0, high = 1, n = arr.size();
        while(high-low>1e-10){
            double mid = low+(high-low)/2.0;
            if(count(arr, mid) >= k){
                high = mid;
            }
            else low = mid;
        }
        
      
        int a = -1, b = -1;
        for(int i=0;i<n;i++){
            float val = arr[i]/low;
            if(floor(val) == ceil(val)){
                a = arr[i];
                b = val;
                if(!binary_search(arr.begin(), arr.end(), b)) continue;
                return {a,b};
            }
        }
        return {-1,-1};
    }



// (1/2)   (1/3)   (1/5)   (2/3)   (2/5)   (3/5)

//     a/mid = b; //for this condtn to hold, a has to be greater than mid.
//     //iterate for each a. If a is greater than m. check for the b. both a and b should be integers/
    
    
//     1/3, if it works for 3, it works for all elts to the right
//     2/3, it might not work. So keep extending to the right until it works.
