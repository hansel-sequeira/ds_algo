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
