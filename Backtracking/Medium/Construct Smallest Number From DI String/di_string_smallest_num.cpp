/*
You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.

 

Example 1:

Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.
Example 2:

Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.
 

Constraints:

1 <= pattern.length <= 8
pattern consists of only the letters 'I' and 'D'.
*/

//TC: O(9!)

string recursive(string pattern, int idx, vector<int>& arr, int previous, string str_so_far){
        char target = pattern[idx];
        string res = "";
        for(int x: arr){
            if(x != -1 and ((x<previous and target=='I') or (x>previous and target=='D'))){
                string temp = to_string(x) + str_so_far;
                if(idx == 0){
                    if(res == "") res = temp;
                    else res = min(res, temp);
                    continue;
                }
                arr[x-1] = -1;
                string return_val = recursive(pattern, idx-1, arr, x, temp);
                arr[x-1] = x;
                if(return_val == ""){
                    continue;
                }
                if(res == "") res = return_val;
                else res = min(res, return_val);
            }
        }
        return res;
    }
    
    
    string smallestNumber(string pattern) {
        string res = "";
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        for(int i=0;i<9;i++){
            arr[i] = -1;
            string return_val = recursive(pattern, pattern.size()-1, arr, i+1, to_string(i+1));
            if(return_val != ""){
                if(res == "") res = return_val;
                else res = min(res, return_val);
            }
            arr[i] = i+1;
        }
        return res;
    }


//stack based: O(n) soln:

string smallestNumber(string pattern) {
        stack<int> s;
        string result;
        for(int i=0;i<=pattern.size();i++){
            s.push(i+1);
            if(pattern[i] == 'I' or i == pattern.size()) {
                while(!s.empty()){
                    result += to_string(s.top());
                    s.pop();
                }
            }
        }
        return result;
    }

//more intuitive greedy soln:
string smallestNumber(string pattern) {
        string result;
        for(int i=1;i<=pattern.size()+1;i++){
            result += to_string(i);
        }
        for(int i=0;i<pattern.size();i++){
            if(pattern[i] == 'I') continue;
            int j = i;
            while(j<pattern.size() and pattern[j] == 'D')
                j++;
            reverse(result.begin()+i, result.begin()+j+1);
            i = j;
        }
        return result;
    }
