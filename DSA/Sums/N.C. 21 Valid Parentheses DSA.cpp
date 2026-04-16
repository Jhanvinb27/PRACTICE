/*
Ques - Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
       determine if the input string is valid.
     - An input string is valid if:
                 - Open brackets must be closed by the same type of brackets.
                 - Open brackets must be closed in the correct order.
                 - Every close bracket has a corresponding open bracket of the same type.
*/
/*
Example - Input: s = "()"
        - Output: true

Example - Input: s = "()[]{}"
        - Output: true

Example - Input: s = "(]"
        - Output: false

Example - Input: s = "([])"
        - Output: true

Example - Input: s = "([)]"
        - Output: false
*/
/*
Approach - store every bracket in order
         - check if the last stored open bracket matches with 1st store close bracket
         - then check if second last stored open bracket matches with last 2nd stored close bracket
         - similarly check for every stored "open" bracket
         - if all are matching and in order then voila!
         - return true or else false.
*/

#include <bits/stdc++.h>
using namespace std;

bool ValidParentheses(string s){
    vector<char> open, close;

    for(char c : s){
        if(c == '(' || c == '{' || c == '[')
            open.push_back(c);
        else
            close.push_back(c);
    }

    if(open.size() != close.size())
        return false;

    int n = open.size();

    for(int i = 0; i < n; i++){
        char o = open[i];
        char c = close[i];

        if((o == '(' && c != ')') ||
           (o == '{' && c != '}') ||
           (o == '[' && c != ']'))
            return false;
    }

    return true;
}
// Time: O(n)
// Space: O(n)
// Wrong answer ...secquence checking mismarch inside array.

/*
Observation - Order matters, not just count
            - Last opened bracket must be closed first
            - Nested structure → LIFO pattern
            - Stack is the perfect data structure
*/

/*
Approach - the last opened bracket must be the first one to close.
         - LIFO (Last In First Out) → use a stack
         - Push opening brackets
         - Match closing brackets with top of stack

Intuition - Always match current closing bracket with the most recent opening bracket
          - If mismatch → invalid
          - If stack becomes empty at end → valid

Algorithm - initialize empty stack
          - traverse each character c in string:
                - if c is opening bracket:
                        - push into stack
                - else (closing bracket):
                        - if stack is empty → return false
                        - check if top matches:
                                - if not → return false
                        - pop from stack
          - if stack is empty → return true
          - else → return false
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            } 
            else{
                if(st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if((top == '(' && c != ')') ||
                   (top == '{' && c != '}') ||
                   (top == '[' && c != ']'))
                    return false;
            }
        }

        return st.empty();
    }
};


// Time : O(n)
// Space : O(n)
