/*
[4,5,6,7,0,1,2] -> pivot is 0               NOTE: THE ELEMENTS ARE UNIQUE, ELSE CAN'T FIND!
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
        //arr[] = {4,5,6,7,1,2,3}
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<high){ //STOP AND CONSIDER: if low==high, what then?? WHY BOTHER? So, terminate!
            int mid = low+(high-low)/2;
            if(nums[mid]>nums[high]){ //left part is sorted, pivot HAS to be in the right
                    //STOP AND CONSIDER: why compare with the right and not the left??
                    //assuming we compared with the left: iteration 1: 7>4 -> {1,2,3}
                    //iteration 2: 2>1 -> {3} WRONG!!    We get the wrong answer when our search space is perfectly sorted
                    //now comparing with right part: iteration 1: 7>3 -> {1,2,3}
                    //iteration 2: 2>3 -> {1,2}
                    //iteration 3: 1>2 -> {1} and then terminate!
                low = mid+1;
            } else { //right part is sorted. pivot is in the left
                high = mid; //keep pushing to the left
            }
        }
        return nums[low];
    }


//a better way to remember this problem is consider a sorted array: [1,2,3]
//iteration 1: 2<3 -> {1,2}
//iteration 2: 1<2 -> {1} and terminate!
