/*
Ques - Given a string s, find the length of the longest substring 
     - without repeating characters.
*/

/*
Example 1 - Input: s = "abcabcbb"
          - Output: 3
          - Explanation: "abc" is the longest substring without repeating characters.

Example 2 - Input: s = "bbbbb"
          - Output: 1
          - Explanation: "b" is the longest substring.

Example 3 - Input: s = "pwwkew"
          - Output: 3
          - Explanation: "wke" is the longest substring.
*/

/*
Approach 1 - Try all substrings
           - For each starting index i
           - Expand substring and check if characters repeat
           - Use a set to track characters

Algorithm - initialize maxLen = 0
          - loop i from 0 to n-1
          - create empty set
          - loop j from i to n-1
          - if s[j] already in set → break
          - insert s[j] into set
          - update maxLen = max(maxLen, j - i + 1)
          - return maxLen
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<char> st;

            for (int j = i; j < n; j++) {
                if (st.count(s[j]))
                    break;
                st.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};

// Time : O(n^2)
// Space : O(n)

/*
Approach - Sliding Window (Two Pointer + HashMap)
         - Maintain a window with unique characters
         - Expand right pointer
         - If duplicate found, move left pointer

Algorithm - initialize:
                - left = 0
                - maxLen = 0
                - map to store last index of characters
          - loop right from 0 to n-1:
                - if s[right] exists in map:
                        - update left = max(left, lastIndex + 1)
                - update map[s[right]] = right
                - update maxLen = max(maxLen, right - left + 1)
          - return maxLen
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            if (mp.count(s[right]))
                left = max(left, mp[s[right]] + 1);

            mp[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// Time : O(n)
// Space : O(n)
