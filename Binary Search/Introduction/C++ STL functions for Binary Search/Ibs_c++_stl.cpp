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



vector<int> arr = {1,2,3,7,9,11};
bool res = binary_search(arr.begin(), arr.end(), 9); 

//The result of binary_search is a BOOLEAN value!

int arr[] = {1,2,3,4,7,9,11};
int n = 7;
bool res = binary_search(arr, arr+n, 4);

//REMEMBER: pass the ADDRESS, NOT the index in the binary_search(), lower_bound() and upper_bound().
//The search for lower_bound() and upper_bound() is from [start_add, end_add). 
//Both of them will return an ITERATOR/ADDRESS AND NOT THE INDEX. So, to retrieve the index, subtract from the base iterator/index!!!
//lower_bound returns either first occ or first element greater than x. If no elt exists, it returns last iterator/address (arr.begin() or arr+n).
//upper_bound returns strictly first elt greater than x or if not exists, returns arr.end() or arr+n
vector<int> arr = {1,2,3,7,7,9,11};
int res = lower_bound(arr.begin(), arr.end(), 7) - arr.begin(); //val is 3
int res = lower_bound(arr.begin(), arr.end(), 10) - arr.begin(); //val is 6
int res = lower_bound(arr.begin(), arr.end(), 12) - arr.begin(); //val is 7
//PAY ATTENTION TO THE NEXT EXAMPLE!
int res = lower_bound(arr.begin(), arr.begin()+3, 12) - arr.begin(); //val is 3

int arr[] = {1,2,3,4,7,9,11};
int n = 7;
int res = lower_bound(arr, arr+n, 5) - arr; //returns 4


vector<int> arr = {1,1,2,3,3};
cout<<lower_bound(arr.begin(), arr.end(), 1) - arr.begin(); //returns 0
cout<<upper_bound(arr.begin(), arr.end(), 1) - arr.begin(); //returns 2

vector<int> arr = {};
cout<<upper_bound(arr, arr+n, 10) - arr; //returns 0 (n)
