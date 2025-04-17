/* 
Ques - https://neetcode.io/problems/is-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        for (char& c : s) {
            for (char& e : t) {
                if (c == e) {
                    return true;
                }
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

*/
