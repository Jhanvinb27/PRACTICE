/*
Ques - You are given a string s and an integer k.
     - You can choose any character of the string and change it to any other character.
     - You can perform this operation at most k times.
     - Return the length of the longest substring containing the same letter 
       after performing at most k operations.
*/

/*
Example 1 - Input: s = "ABAB", k = 2
          - Output: 4
          - Explanation: Replace both 'A' with 'B' or vice versa.

Example 2 - Input: s = "AABABBA", k = 1
          - Output: 4
          - Explanation: Replace one 'A' → longest substring "AABA" or "ABBA".
*/

/*
Approach 1 - Try all substrings
           - For each substring, count frequency of characters
           - Find max frequency in substring
           - If (length - maxFreq) <= k → valid substring

Algorithm - initialize maxLen = 0
          - loop i from 0 to n-1
          - create freq array of size 26
          - loop j from i to n-1
          - increment freq[s[j]]
          - find maxFreq in freq
          - if (j - i + 1 - maxFreq) <= k:
                - update maxLen
          - return maxLen
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int maxFreq = 0;

            for (int j = i; j < n; j++) {
                freq[s[j] - 'A']++;
                maxFreq = max(maxFreq, freq[s[j] - 'A']);

                int len = j - i + 1;
                if (len - maxFreq <= k)
                    maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};

// Time : O(n^2)
// Space : O(1)

/*
Approach - Sliding Window
         - Maintain window where (window size - maxFreq) <= k
         - maxFreq = count of most frequent char in window

Algorithm - initialize:
                - left = 0
                - maxLen = 0
                - maxFreq = 0
                - freq array of size 26
          - loop right from 0 to n-1:
                - increment freq[s[right]]
                - update maxFreq
                - while (window size - maxFreq) > k:
                        - decrement freq[s[left]]
                        - left++
                - update maxLen = max(maxLen, window size)
          - return maxLen
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, maxLen = 0, maxFreq = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// Time : O(n)
// Space : O(1)
