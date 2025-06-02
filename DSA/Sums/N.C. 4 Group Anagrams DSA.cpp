/*
Ques - https://neetcode.io/problems/anagram-groups

Group Anagrams

Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.
An anagram is a string that contains the exact same characters as another string, 
but the order of the characters can be different.

Example 1:
Input: strs = ["act","pots","tops","cat","stop","hat"]
Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]

Example 2:
Input: strs = ["x"]
Output: [["x"]]

Example 3:
Input: strs = [""]
Output: [[""]]

Constraints:
1 <= strs.length <= 1000.
0 <= strs[i].length <= 100
strs[i] is made up of lowercase English letters.
*/

/*
Approach -
  Given : - an array of strings strs
  Task :  - to group annagrams together into sublists
*/

/*
Solution 1 - we can sort each word
           - and if the same word is repeated the next 1 time [i+1], or two times [i+2] or more ...
           - we'll make a sublist and store it there 
           - similarly we can store other words as well
           - next we can store all the sub list in the final result array and can return it.
- Let's Code it:
*/
# include <bits/stdc++.h>
using namespace std;
// M - Not clear what is explained in solution portion. No complexity analysis.
// '+' operator is used for string and int shich is incompatible type ig?
// what is push_backstrs() exactly?
// optimal approach seems to be correct.
  vector <vector<string>> GroupedAnagrams (vector<string>& strs){
    sort(strs.begin(), strs.end());
    vector <string> sublists;
    for (string s : strs){
      if (s==s+1){
        sublists.push_backstrs[s];
      }
   }
    return sublists;
}
int main() {
  strs = ["act","pots","tops","cat","stop","hat"]
  vector<string> result = GroupedAnagrams;
}


/*
OPTIMAL 
    - we will extract each lettter from each word of the array
    - then we will use positions from 0-25 number for a to z : for each and every single word of the array
    - this is to keep the track of appearance of each word.
    - then we will group a to z based on their number count of letters
    i.e if "cat" -> a=1,b=0,c=1,d=0,...,t=1,u=0,v=0,...,z=0
    and for some othe word "pot" -> a=0,b=0,...,o=1,p=1,q=0,r=0,...,t=1,u=0,v=0,...,z=0
    - so judging by the count of each letter and it's frequency we will group them together
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string word : strs) {
            // a frequency array for 26 letters, all set to 0
            vector<int> count(26, 0);
            

            for (char ch : word) {
                count[ch - 'a']++;  // 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
            }

            string key = "";
            for (int i = 0; i < 26; ++i) {
                key += to_string(count[i]) + "#";  
            }
            groups[key].push_back(word);
        }

        //convert map to result vector
        vector<vector<string>> result;
        for (auto it : groups) {
            result.push_back(it.second);
        }

        return result;
    }
};

// Time Complexity: O(N * K); Where: N = number of words in the input list strs,
//K = maximum length of a single word

//Space Complexity: O(N * K)
// Why?
// Map storage: In the worst case, 
//each word may form a unique group → storing N keys and N words → O(N * K)
// Key strings: Each key is a string of size ~52 characters 
//("1#0#0#..." for 26 letters), which is constant → negligible.
// Count array: Uses O(26) = O(1) space per word (temporary).
// So overall:
// Space = O(N * K) for storing all grouped words.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(pair.second);
        }

        return result;
    }
};
/*
Time Complexity: O(N × K log K)
Where:
N = number of strings in strs
K = maximum length of any string
Why?
For each of the N strings:
Copying str → O(K)
Sorting the string → O(K log K)
Inserting into unordered_map → average O(1) (amortized)
Final loop over the map to collect results takes O(N), since every word is added once.
Total: O(N × K log K)
Space Complexity: O(N × K)
Why?
unordered_map<string, vector<string>> stores up to N unique keys and all N original strings → O(N × K)
Sorted copies of each string → each of length K
Result vector stores all original strings in groups → O(N × K)
Total: O(N × K)
  */
