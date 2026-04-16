/*
Ques - You are given an array of strings tokens that represents 
     - an arithmetic expression in Reverse Polish Notation (RPN).
     - Evaluate the expression and return the result.
     - Valid operators are '+', '-', '*', '/'
     - Division truncates toward zero
*/

/*
Example 1 - Input: tokens = ["2","1","+","3","*"]
          - Output: 9
          - Explanation: ((2 + 1) * 3) = 9

Example 2 - Input: tokens = ["4","13","5","/","+"]
          - Output: 6
          - Explanation: (4 + (13 / 5)) = 6

Example 3 - Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
          - Output: 22
*/

/*
Observation -
- Operators come AFTER operands (postfix form)
- No need for brackets or precedence handling
- Always operate on last two numbers
- Stack follows LIFO → perfect fit
*/

/*
Approach - Use stack
         - Traverse tokens from left to right
         - If number → push into stack
         - If operator:
                - pop top two elements
                - apply operation
                - push result back

Intuition -
- Most recent numbers are used first
- Stack helps track intermediate results
- Each operator reduces 2 numbers → 1 result
*/

/*
Algorithm - initialize empty stack
          - for each token:
                - if token is number:
                        - push into stack
                - else (operator):
                        - pop b (top)
                        - pop a (second top)
                        - compute a op b
                        - push result
          - final answer = stack.top()
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if(token == "+") st.push(a + b);
                else if(token == "-") st.push(a - b);
                else if(token == "*") st.push(a * b);
                else st.push(a / b);
            }
            else{
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

// Time : O(n)
// Space : O(n)
