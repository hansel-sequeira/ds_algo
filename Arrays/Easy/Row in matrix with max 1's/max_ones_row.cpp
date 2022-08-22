/*
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

Example 2:

Input: 
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing)

Constraints:
1 ≤ N, M ≤ 103
0 ≤ Arr[i][j] ≤ 1 
*/


//not explaining the (n*m) or the (n*logm) solution. Let's directly dive into the (n+m) solution:

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int res = -1, j = m-1;
	    for(int i=0;i<n;i++){
	        if(arr[i][m-1] == 0) continue;
	        while(j>=0 and arr[i][j] == 1){
	            j--;
	            res = i;
	        }
	    }
	    return res;
	}

//intuition: assume you're at the first row: (0 0 0 1 1 1) and you know that the max so far is 3 (first occ). There is no reason to iterate from m-1 from the next
//row onwards. simply check from the 2nd index. If the 2nd index is a match, keep probing backwards till it's a 1 and don't forget to update the max row.
