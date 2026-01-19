/* 
Ques - https://neetcode.io/problems/is-anagram

Valid Anagram

Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
An anagram is a string that contains the exact same characters as another string, 
but the order of the characters can be different.

Example 1:
Input: s = "racecar", t = "carrace"
Output: true

Example 2:
Input: s = "jar", t = "jam"
Output: false
Constraints:

s and t consist of lowercase English letters.
*/

/*
Approach 
*/
class Solution {
public:
// M - This function is incorrect.
// Observe if s and t are anagrams the number of occurrence of a single alphabet remain same.
// Best approach will be maintain the frequency of alphabets for both string s and t.
// And in the end match frequency tables.
// Time complexity - O(max(n,m)), Space complexity - O(1) for storing frequency of 26 alphabets
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        for (char& c : s) {
            for (char& e : t) {
                return s== t;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

#include <iostream>
#include <unordered_map>
using namespace std;

// Define the Solution class with the isAnagram method
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> countMap;

        // Count characters in the first string
        for (char c : s) {
            countMap[c]++;
        }

        // Subtract character counts using the second string
        for (char c : t) {
            countMap[c]--;
            if (countMap[c] < 0) {
                return false;
            }
        }

        return true;
    }
};
