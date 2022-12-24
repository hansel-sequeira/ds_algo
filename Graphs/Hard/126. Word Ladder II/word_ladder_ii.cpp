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




//Optimal solution:

class Solution {
private:
    string startWord;
    unordered_map<string,int> umap;
public:

    void dfs(string word, vector<string>& interim, vector<vector<string>>& result){
        if(word == startWord){
            reverse(interim.begin(), interim.end());
            result.push_back(interim);
            reverse(interim.begin(), interim.end());
            return;
        }
        int steps = umap[word];
        for(int i=0;i<word.length();i++){
            for(int j=0;j<26;j++){
                //going up the path
                char ch = word[i];
                word[i] = j+'a';
                if(umap.find(word) != umap.end() and umap[word]==steps-1){
                    interim.push_back(word);
                    dfs(word, interim, result);
                    interim.pop_back();
                }
                word[i] = ch;
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        this->startWord = beginWord;
        vector<vector<string>> result;
        unordered_set<string> uset(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        umap[beginWord] = 1;
        uset.erase(beginWord);
        while(!q.empty()){
            string str = q.front();
            q.pop();

            if(str == endWord)
                break;

            int len = str.length();
            int steps = umap[str];
            for(int i=0;i<len;i++){
                for(int j=0;j<26;j++){
                    char ch = str[i];
                    str[i] = j+'a';
                    if(uset.find(str) != uset.end()){
                        q.push(str);
                        umap[str] = steps + 1;
                        uset.erase(str);
                    }
                    str[i] = ch;
                }
            }

        }

        if(umap.find(endWord) != umap.end()){
            vector<string> interim;
            interim.push_back(endWord);
            dfs(endWord, interim, result);
        }
        return result;
    }
};     

