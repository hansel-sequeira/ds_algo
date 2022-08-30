/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two
numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
*/
 int *findTwoElement(int *arr, int n) {
        // code here
        int xr = 0;
        for(int i=1;i<=n;i++) xr^=i;
        for(int i=0;i<n;i++) xr^=arr[i];
        int differ = xr&(~(xr-1));

        int bucket1 = 0, bucket2 = 0;
        for(int i=0;i<n;i++){
            if(differ & arr[i])
                bucket1 ^= arr[i];
            else bucket2 ^= arr[i];
        }
        for(int i=1;i<=n;i++){
            if(differ & i)
                bucket1 ^= i;
            else bucket2 ^= i;
        }
        
        int missing = bucket1, repeating = bucket2;
        for(int i=0;i<n;i++){
            if(arr[i] == bucket1){
                missing = bucket2;
                repeating = bucket1;
                break;
            }
        }
        int *res = new int[2];
        res[0]=repeating; res[1] = missing;
        return res;
    }



//another approach:

vector<int>repeatedNumber(const vector<int> &A) {
    long long int len = A.size();
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
    
    for(int i=0;i<A.size(); i++){
       Sum_N -= (long long int)A[i];
       Sum_NSq -= (long long int)A[i]*(long long int)A[i];
    }
    
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
    repeating= missingNumber - Sum_N;
    vector <int> ans;
    ans.push_back(repeating);
    ans.push_back(missingNumber);
    return ans;
    
}
