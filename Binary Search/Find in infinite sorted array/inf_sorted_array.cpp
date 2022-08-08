/*
1 2 3 4 7 9 11 14 ...
Given an infinite sorted array, check if a number exists or not. If yes, print the index
*/

intuition: window size initially is 2 [0,1]. If elt at high < tgt -> high = 2*high. Window size exponentially increases.
assuming the window containing target (high ptr) is at position n, it took us logn steps to reach there. Then on that window, simply apply a binary search for the tgt.
TC: logn (to find the window) + logn (bs on that window).
remember: n is the position of the high pointer. NOT the target!

int binary_search(int arr[], int target){
 int low = 0, high = 1;
  while(arr[high]<target){
    low = high; //slight optimization;
    high = 2*high;
  }
  binary_search(arr, low, high, target);
}
 
