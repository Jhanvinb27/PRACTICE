/*
Given - a string
return - bool : true or false
check if it's Palindrome
*/

/*
Input: s = "Was it a car or a cat I saw?"
Output: true

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/

#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        if (!((s[i] >= '0' && s[i] <= '9') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z'))) {
              // if(iswalnum(s[i]) && iswalnum(s[j]))
            i++;
            continue;
        }
        if (!((s[j] >= '0' && s[j] <= '9') ||
              (s[j] >= 'a' && s[j] <= 'z') ||
              (s[j] >= 'A' && s[j] <= 'Z'))) {
              // if(tolower(s[i])==tolower(s[j]))
            j--;
            continue;
        }
        char left = s[i];
        char right = s[j];
        if (left >= 'A' && left <= 'Z') left += 32;
            // 'A' = 65
           //'a' = 97
          // 97 - 65 = 32  
         // so 'A' + 32 → 'a'
        // 'A' != 'a'  (ASCII)
       // but logically they should match
        if (right >= 'A' && right <= 'Z') right += 32; // ONLY add 32 if the character is capital
        if (left != right) return false;
        i++;
        j--;
    }
    return true;
}
int main() {
    string s;
    getline(cin, s);
    cout << (isPalindrome(s) ? "true" : "false");
    return 0;
}

// ANOTHER SHORTER WAY 
while(i<j){
    if(iswalnum(s[i]) && iswalnum(s[j])){
        if(tolower(s[i])==tolower(s[j])){
            i++;
            j--;
        }
            else
              return 0;
            }
        if(!iswalnum(s[i]))
           i++;
        if(!iswalnum(s[j]))
           j--;    
      }
    return 1;
}
