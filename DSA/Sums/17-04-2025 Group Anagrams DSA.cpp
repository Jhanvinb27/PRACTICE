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



















*/
