/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/


//tc average: n*(m*logm)
//tc worst: n^2*m*logm
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;
        for(string str: strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            umap[temp].push_back(str);
        }
        for(auto it: umap){
           res.push_back(it.second);
        }
        return res;
    }
};




//tc: n*m*log(n) where n is the length
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        map<vector<int>, vector<string>> umap;
        for(string str: strs){
            vector<int> count(26, 0);
            for(char ch: str)
                count[ch-'a']++;
            umap[count].push_back(str);
        }
        for(auto it: umap){
           res.push_back(it.second);
        }
        return res;
    }
};
