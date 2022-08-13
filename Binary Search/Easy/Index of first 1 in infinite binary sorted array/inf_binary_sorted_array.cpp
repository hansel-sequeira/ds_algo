/*
0 0 0 0 0 0 0 0 0 1 1 1 1 .....
Find the index of the first 1
*/

intuition: find an appropriate window and then apply first occ function on that window!
  
int binary_search(int arr[]){
  int low = 0, high = 1;
  while(arr[high]!=1){
    low = high;
    high = 2*high;
  }
  return first_occ(low, high, 1);
}
