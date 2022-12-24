/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no
such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
*/


//correct but slightly suboptimal approach (won't pass a few testcases)
/*
TC analysis:
assuming a binary tree (bat -> hat and bit)
levels of the binary tree = N (N is total words)
Therefore, total nodes being probed = 2^N - 1 - we're assuming each node will be a vector with just a single string
So, at the worst case, the TC is exponential
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> uset(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        while(!q.empty()){
            int size = q.size();
            unordered_set<string> level_words;
            while(size--){ //where size denotes the nodes in a particular level
                vector<string> seq = q.front();
                q.pop();
                //extracting the last word in the sequence
                string word = seq[seq.size()-1];
                //probe all possibilities to add to the queue for the next level

                for(int i=0;i<word.length();i++){
                    string new_word = word;
                    for(int j=0;j<26;j++){
                        new_word[i] = j+'a';
                        if(uset.find(new_word) != uset.end()){
                            vector<string> new_seq = seq;
                            new_seq.push_back(new_word); 
                            q.push(new_seq);
                            level_words.insert(new_word);
                            if(new_word == endWord)
                                result.push_back(new_seq);
                        }
                    }
                }
            }   
            //iteration over all the nodes at a level done at this point
            if(result.size())
                break;
            //now, pop out all the new words generated at this level
            for(string str: level_words)
                uset.erase(str);
        }
        return result;
    }
};
