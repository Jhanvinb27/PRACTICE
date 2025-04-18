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

  
