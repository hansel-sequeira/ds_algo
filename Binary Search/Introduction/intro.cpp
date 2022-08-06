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

/*
Time complexity: O(logn)

intuition: on every iteration of the loop, we're basically reducing our search space by half. Hence, the logn tc.
Mathematical intution:
search space: n -> n/2 -> n/4 ... 1
n/2^0 -> n/2^1 -> n/2^2 -> n/2^k where n/2^k = 1
or n = 2^k or k = log n base 2 and k is the total number of iterations
Hence, TC is log(2) n
*/
