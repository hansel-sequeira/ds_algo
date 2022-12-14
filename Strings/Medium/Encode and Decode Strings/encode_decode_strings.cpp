/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Please implement encode and decode

Example
Example1

Input: ["lint","code","love","you"]
Output: ["lint","code","love","you"]
Explanation:
One possible encode method is: "lint:;code:;love:;you"
Example2

Input: ["we", "say", ":", "yes"]
Output: ["we", "say", ":", "yes"]
Explanation:
One possible encode method is: "we:;say:;:::;yes"
*/

class Solution {
private:
    vector<int> count;
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string result;
        for(string str: strs){
            result += str;
            count.push_back(str.length());
        }
        return result;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> result;
        int prev = 0;
        for(int i=0;i<count.size();i++){
            int letters = count[i];
            result.push_back(str.substr(prev, letters));
            prev += letters;
        }
        return result;
    }
};


//optimal solution:

//intuition:  lint code loves
//encode to 4#lint4#code...
//why use #? what if number was 2+ digits?

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string result;
        for(string str: strs){
            result += to_string(str.length())+"#"+str;
        }
        return result;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> result;
        int i = 0;
        while(i<str.length()){
            //first extract the length
            string length;
            while(str[i]!='#')
                length += str[i++];
            int len = stoi(length);
            result.push_back(str.substr(i+1, len));
            i += len+1;
        }
        return result;
    }
};
