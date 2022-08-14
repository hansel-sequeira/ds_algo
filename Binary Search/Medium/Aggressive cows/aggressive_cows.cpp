/*
Given an array of length ‘N’, where each element denotes the position of a stall. Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive. To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance.
Eg

array: 1,2,4,8,9  &  k=3
O/P: 3
Explaination: 1st cow at stall 1 , 2nd cow at stall 4 and 3rd cow at stall 8
*/

bool isPoss(vector<int>& arr, int target, int cows){
    int prev_pos = arr[0], count = 1;
    for(int i=1;i<arr.size();i++){
        if(arr[i]-prev_pos < target) continue;
        count++;
        prev_pos = arr[i];
    }
    return count>=cows;
}

int aggressiveCows(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int low = 1, high = arr[n-1]-arr[0], res = 1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(isPoss(arr, mid, k)){
            res = mid;
            low = mid+1;
        } else high = mid-1;
    }
    return res;
}
