/*
Ques - https://neetcode.io/problems/is-palindrome
*/
/*
Given a string s, return true if it is a palindrome, otherwise return false.
A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

Example 1:
Input: s = "Was it a car or a cat I saw?"
Output: true
Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.

Example 2:
Input: s = "tab a cat"
Output: false
Explanation: "tabacat" is not a palindrome.

Constraints:
1 <= s.length <= 1000
s is made up of only printable ASCII characters.
*/

// normal char palindrome check

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

// Time Complexity : O(n)
// Space Compleexity : O(1)

// but with sentence 

class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";

        // keep only letters and numbers, convert to lowercase
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }

        int left = 0, right = cleaned.size() - 1;

        while (left < right) {
            if (cleaned[left] != cleaned[right])
                return false;
            left++;
            right--;
        }

        return true;
    }
};

// Time Complexity : O(n)
// Space Compleexity : O(n)
