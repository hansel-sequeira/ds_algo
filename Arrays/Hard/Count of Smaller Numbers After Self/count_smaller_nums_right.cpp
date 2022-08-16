/*
Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

//Note: all such patterns where you have (i<j) and some condition to check on the basis of nums[i] and nums[j] =====> merge sort pattern
//simple merge sort won't work here because we need to keep track of the actual index of the elements in the sorted array and they'd obviously be shuffled about
//when we merge and sort the array. So rather than dealing with the original arr, deal with a pair <nums[i], i>. This way we'd always have track of the original idx

class Solution {

public:

    
    void merge_sort_util(vector<pair<int,int>>& nums, int low, int high, vector<int>& res){
        if(low>high || low == high) return;
        int mid = low+(high-low)/2;
        merge_sort_util(nums, low, mid, res);
        merge_sort_util(nums, mid+1, high, res);
        for(int i=low, j = mid+1; i<=mid; i++){
            while(j<=high and nums[j].first < nums[i].first) 
                j++;
            res[nums[i].second] += (j-mid-1);
        }
        inplace_merge(nums.begin()+low, nums.begin()+mid+1, nums.begin()+high+1);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<pair<int,int>> ds;
        for(int i=0;i<nums.size();i++){
            ds.push_back({nums[i], i});
        }
        merge_sort_util(ds, 0, nums.size()-1, res);
        return res;
    }
};



//note: inplace_merge(nums.begin(), nums.mid(), nums.end()) --> works best when we have iterators to begin with. nums.mid() is start of second arr.
//nums.end() is not the last element! it's pointing outside the array!

#define iterator vector<pair<int,int>>::iterator 
class Solution {

public:

    
    void merge_sort_util(vector<pair<int,int>>& nums, iterator low, iterator high, vector<int>& res){
        if(high-low<=1) return;
        iterator mid = low+(high-low)/2;
        merge_sort_util(nums, low, mid, res);
        merge_sort_util(nums, mid, high, res);
        for(auto i=low, j = mid; i<mid; i++){
            while(j<high and (*j).first < (*i).first) 
                j++;
            res[(*i).second] += (j-mid);
        }
        inplace_merge(low, mid, high);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<pair<int,int>> ds;
        for(int i=0;i<nums.size();i++){
            ds.push_back({nums[i], i});
        }
        merge_sort_util(ds, ds.begin(), ds.end(), res);
        return res;
    }
};


//tc for inplace_merge(): linear if enough space in memory, else nlogn (shell sorting)
