/*
[4,5,6,7,0,1,2] -> pivot is 0
Variations of this question: 
1) find pivot (element or index)
2) find clockwise operations done (0,1,2 -> giving a total of 3)
3) find anticlockwise operations done (4,5,6,7 -> a total of 4)
*/

//also works for n = 1
int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1, res = nums[0];
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] >= nums[0]) low = mid+1;
            else{
                res = nums[mid];
                high = mid-1;
            }
        }
        return res;
    }

//standard approach: 

int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(nums[mid]>nums[high]){ //left part is sorted, pivot HAS to be in the right
                low = mid+1;
            } else { //right part is sorted. pivot is in the left
                high = mid;
            }
        }
        return nums[low];
    }
