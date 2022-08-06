/*
Given a sorted array of  (may contain duplicate nums) integers, find the first and last position of a target element.  
*/

//naive way: 
int first = -1, last = -1;
for(int i=0;i<n;i++){
  if(arr[i] == target){
      if(first == -1){
          first = last = i;
      } else if(i>last){
          last = i;      
      }
  }
}

TC: linear scan O(n)
  
//optimal way is to simple use binary search
  
  int last_occ(vector<int>& arr, int x){
        int n = arr.size(), result = -1;
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid] == x){
                result = mid;
                low = mid+1;
            } else if(arr[mid] < x) low = mid+1;
            else high = mid-1;
        }
        return result;
    }
    
    int first_occ(vector<int>& arr, int x){
        int n = arr.size(), result = -1;
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid] == x){
                result = mid;
                high = mid-1;
            } else if(arr[mid] < x) low = mid+1;
            else high = mid-1;
        }
        return result;
    }
    
    
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int first = first_occ(arr, target);
        int last = last_occ(arr, target);
        vector<int> res = {first, last};
        return res;
    }


//using c++ stl functions lower_bound() and upper_bound():
vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int first = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        if(first == n || arr[first] != target) first = -1; //first == n handles elt not present (and greater than all elts in array) & also n = 0 condtn
        int last = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        if(last == 0 || arr[last-1] != target) last = -1; //last = 0 handles elt not present (smaller than all elts in array) & n = 0 condtn
        else last--; // DO NOT FORGET THIS LINE!
        vector<int> res = {first, last};
        return res;
    }


//cleaner code making use of binary_search(). If elt is not present, obviously -1,-1 to be returned, eliminating the need of additional checks on lb() and ub().
vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        if(binary_search(arr.begin(), arr.end(), target) == false){
            return {-1,-1};
        }
        int first = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        int last = upper_bound(arr.begin(), arr.end(), target) - arr.begin() - 1;
        vector<int> res = {first, last};
        return res;
    }
