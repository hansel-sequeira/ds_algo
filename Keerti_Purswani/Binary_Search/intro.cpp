/*
1) when do you use it? -> if the input array is sorted (not always the case!)
2) a better way to rephrase point 1 is if we have a confined search space and it is monotonic in nature (increasing / decreasing).

Given a sorted array of integers, check if a value x exists in the array or not. If it does exist, return the index, else return -1
*/


int binary_search(vector<int>& arr, int x){
	int n = arr.size();
	int low = 0, high = n-1;
	while(low<=high){
		int mid = low+(high-low)/2;
		if(arr[mid] == x){
			return mid;
		} else if(arr[mid] > x){
			high = mid-1;
		} else {
			low = mid+1;
		}
	}
	return -1;
}
