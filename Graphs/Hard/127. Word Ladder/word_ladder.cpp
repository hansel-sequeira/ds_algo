/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/

//tc: n*26 === n (where n is the total words in the word list)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        unordered_set<string> seen;
        for(string str: wordList)
            s.insert(str);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        seen.insert(beginWord);
        while(!q.empty()){
            auto [str, level] = q.front();
            q.pop();
            if(str == endWord)
                return level;
            for(int i=0;i<str.length();i++){
                for(int j=0;j<26;j++){
                    string new_str = str;
                    new_str[i] = j+'a';
                    if(new_str != str  and  s.find(new_str) != s.end()
                       and seen.find(new_str) == seen.end()){
                        seen.insert(new_str);
                        q.push({new_str, level+1});
                    }
                }
            }
        }
        return 0;
    }
};
