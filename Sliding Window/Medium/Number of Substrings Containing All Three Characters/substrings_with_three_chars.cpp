/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0, n = s.length();
        int left = 0;
        unordered_map<char,int> umap;
        for(int right=0;right<n;right++){
            umap[s[right]]++;
            while(umap.size()>=3){
                if(--umap[s[left]] == 0)
                    umap.erase(s[left]);
                left++;
            }
            count += left;
        }
        return count;
    }
};

