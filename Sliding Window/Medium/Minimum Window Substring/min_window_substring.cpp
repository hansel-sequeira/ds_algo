/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

class Solution {
public:
    string minWindow(string s, string t) {
        string result = "";
        int p = 0, q = 0;
        unordered_map<char, int> umap;
        for(char ch: t)
            umap[ch]++;
        //initialize the first window possible
        int required_vars = umap.size();
        while(q<s.length() and required_vars){
            if(umap.find(s[q]) != umap.end()) {
                umap[s[q]]--;
                if(umap[s[q]] == 0)
                    required_vars--;
            }
            q++;
        }
        if(required_vars)
            return result;
        
        while(p<q and (umap.find(s[p])==umap.end() or umap[s[p]]!=0)){
            if(umap.find(s[p])!=umap.end())
                umap[s[p]]++;
            p++;
        }
        result = s.substr(p, q-p);

        while(q<s.length()){
            if(umap.find(s[q]) != umap.end()){
                umap[s[q]]--;
                //try shrinking the left pointer
                while(p<q and ( umap.find(s[p])==umap.end() or umap[s[p]]!=0 )){
                    if(umap.find(s[p])!=umap.end())
                        umap[s[p]]++;
                    p++;
                }
            }
            q++;
            if(result.length() > (q-p))
                result = s.substr(p, q-p);
        }
        return result;
    }
};




//Even more elegant solution:

class Solution {
public:
    string minWindow(string s, string t) {
        string result = "";
        unordered_map<char,int> countS, countT;
        for(char ch: t)
            countT[ch]++;
        int required = countT.size();
        int p = 0, q = 0;
        while(q<s.size()){
            char ch = s[q];
            countS[ch]++;
            if(countT.find(ch)!=countT.end() and countS[ch] == countT[ch])
                required--;
            while(required == 0){
                if(result=="" or result.size()>(q-p+1)){
                    result = s.substr(p, q-p+1);
                }
                --countS[s[p]];
                if(countT.find(s[p])!=countT.end() and countS[s[p]] < countT[s[p]])
                    required++;
                p++;
            }
            q++;
        }
        return result; 
    }
};
