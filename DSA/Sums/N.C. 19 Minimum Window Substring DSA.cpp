/*
Ques - Given two strings s and t of lengths m and n respectively,
     - return the minimum window substring of s such that every character in t
       (including duplicates) is included in the window.
     - If no such substring exists, return "".
*/

/*
Example 1 - Input: s = "ADOBECODEBANC", t = "ABC"
          - Output: "BANC"

Example 2 - Input: s = "a", t = "a"
          - Output: "a"

Example 3 - Input: s = "a", t = "aa"
          - Output: ""
*/

/*
Observation -
- Order does NOT matter, only frequency matters
- We must include all characters of t (including duplicates)
- Window can have extra characters, but must at least satisfy t
- Goal is to find the SMALLEST such valid window
*/

/*
Approach 1 - Try all substrings
           - For each substring, check if it contains all chars of t
           - Use frequency maps to compare

Intuition -
- Generate all possible substrings
- For each substring, check if it satisfies requirement of t
- Keep track of smallest valid substring

Algorithm - initialize minLen = INT_MAX, startIndex = -1
          - create freqT map for string t
          - loop i from 0 to n-1
          - create freqS map
          - loop j from i to n-1
          - increment freqS[s[j]]
          - check if freqS satisfies freqT
          - if yes:
                - update minLen and startIndex
                - break (no need to expand further)
          - return substring using startIndex and minLen
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> freqT;

        for (char c : t)
            freqT[c]++;

        int minLen = INT_MAX, startIndex = -1;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freqS;

            for (int j = i; j < n; j++) {
                freqS[s[j]]++;

                bool valid = true;
                for (auto &p : freqT) {
                    if (freqS[p.first] < p.second) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    if (j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        startIndex = i;
                    }
                    break;
                }
            }
        }

        if (startIndex == -1)
            return "";

        return s.substr(startIndex, minLen);
    }
};

// Time : O(n^2 * 26)
// Space : O(1)

/*
Approach - Sliding Window (Two Pointer + Frequency Map)
         - Expand window until it becomes valid
         - Then shrink to find minimum

Intuition -
- We need a window that contains all characters of t
- Expand right pointer to satisfy condition
- Once valid, try shrinking from left to minimize window
- Keep updating minimum length

Algorithm - initialize:
                - freqT map for t
                - freqS map
                - left = 0
                - formed = 0 (matched characters)
                - required = size of freqT
                - minLen = INT_MAX, startIndex = 0
          - loop right from 0 to n-1:
                - add s[right] to freqS
                - if freq matches freqT → formed++
          - while formed == required:
                - update minLen and startIndex
                - remove s[left] from freqS
                - if it breaks condition → formed--
                - left++
          - return substring
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freqT, freqS;

        for (char c : t)
            freqT[c]++;

        int left = 0, formed = 0;
        int required = freqT.size();

        int minLen = INT_MAX, startIndex = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            freqS[c]++;

            if (freqT.count(c) && freqS[c] == freqT[c])
                formed++;

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                char leftChar = s[left];
                freqS[leftChar]--;

                if (freqT.count(leftChar) && freqS[leftChar] < freqT[leftChar])
                    formed--;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};

// Time : O(n)
// Space : O(1)
