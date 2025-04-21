/*
Ques - https://neetcode.io/problems/string-encode-and-decode

Given - a list of strings 
      - and we have to ENCODE and DECODE the list
      - ENCODE such that the given list of strings gets converted into a single string
      - DECODE such that it again  transforms into the original string
*/
/*
Solution 1 - we can use a hashmap to store <"string",index> 
           - well we will change it to <index,"string"> because key should be unique and 
              string might have duplicate values
           - then we can store all the given input lists of strings into one hashmap
           - and then we can create an array to store the encoded result of the string into one array
           - and when we want to decode we can simply refer to the given hashmap and execute the decoding 
           - Let's Code it:
// M - This approach is incorrect as no shared map object allowed among the two functions. and if allowed still we don't the variables like n which is used in the code for decoding 
and map size also grows at higher rate.
Last approach with adding special character while contacting the strings is correct.
*/

// for encoding
# include<bits/stdc++.h>
using namespace std;

string encode(vector<string>& strs) {
        unordered_map<int,string> map;
        string result;
        for(int i = 0; i < strs.size(); i++){
            map[i] = strs[i];
        }
        for (int i=0; i < map.size(); i++ ){
            result += (map[i]) ;
        }
        return result;
    }
int main() {
    vector<string> input = {"bat", "ball", "cat"};
    string encoded = encode(input);
    cout << "Encoded string: " << encoded << endl;
    return 0;
}

// for decoding
vector<string> decode(string s){
      vector<string> output;
      for(int i=0; i < n; i++){
            output.push_back(map[i]);
      }
      return output;
}

// NeetCode solution
public:
    unordered_map<int, string> map;
    string encode(vector<string>& strs) {
        string result;
        for(int i = 0; i < strs.size(); i++){
            map[i] = strs[i];
        }
        for (int i=0; i < map.size(); i++ ){
            result += to_string(map[i].size());
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> output;
        for (int i = 0; i < map.size(); i++) {
            output.push_back(map[i]);
        }
    return output;
    }
};

// Time Complexity : O(n) 
// Space Complexity : O(n)

/* 
Recommended Time & Space Complexity - Aim for a solution with O(m) time 
                                             - for each encode() and decode() call and 
                                    - O(m+n) space, 
                                             - where m is the sum of lengths of all the strings and n is the number of strings.
*/

class Solution {
public:
    string encode(vector<string>& strs) {
        string result;
        for (string& s : strs) {
            result += to_string(s.size()) + '#' + s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return result;
    }
};

