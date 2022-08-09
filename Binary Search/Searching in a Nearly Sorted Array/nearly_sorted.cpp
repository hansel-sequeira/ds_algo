/*
nearly sorted means that an element at index i, could either have its correct position at index i, i-1 or i+1;
original sorted arr: 5 10 20 30 40
after rearrange:     5 10 30 20 40
*/

int binary_search(int arr[], int n, int target){
  int low = 0, high = n-1;
  while(low<=high){
     int mid = low+(high-low)/2;
     //we selected an index i. The element could lie at either i, i-1 or i+1;
     if(arr[mid] == target) return mid;
     if(mid>0 and arr[mid-1] == target) return mid-1;
     if(mid<n-1 and arr[mid+1] == target) return mid+1;
     //if the element is not in this window size of 3, we have to go either to the left or to the right
     //... a b c d e f ..
     // consider the middle element is c and the initial test failed. now look at a. a could either lie there, to its left or to b's position.
     //so if our elt <=a , go left. same with right
     if(mid-2>=0 and target <= arr[mid-2] high = mid-2;
     else low = mid+2;
  }
    return -1;
}
