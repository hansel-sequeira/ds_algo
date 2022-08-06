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
