/*
Ques - Design a stack that supports push, pop, top, and retrieving 
     - the minimum element in constant time.
     - Implement the MinStack class:
            - MinStack() initializes the stack object
            - void push(int val) pushes the element onto the stack
            - void pop() removes the element on the top of the stack
            - int top() gets the top element of the stack
            - int getMin() retrieves the minimum element in the stack
*/

/*
Example -
Input:
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output:
[null,null,null,null,-3,null,0,-2]
*/

/*
Observation -
- We need minimum in O(1)
- Normal stack gives top in O(1) but not minimum
- Brute force (scan stack) → O(n)
- We need to store minimum along with elements
*/

/*
Approach 1 - Brute Force
           - Use a single stack
           - For getMin():
                - traverse entire stack
                - find minimum
Algorithm -
          - push → normal push
          - pop → normal pop
          - top → return top
          - getMin → loop through stack to find minimum
*/

// Time : O(n) for getMin
// Space : O(n)

/*
Approach 2 - Optimal (Two Stacks)
           - Use:
                - main stack (store elements)
                - min stack (store minimums)
           - min stack keeps track of current minimum

Intuition -
- At every step, we want quick access to minimum
- So we store the minimum till that point in another stack

Algorithm -
          - push(val):
                - push into main stack
                - if min stack empty OR val <= min.top():
                        - push val into min stack
          - pop():
                - if top of main == top of min:
                        - pop from min stack
                - pop from main stack
          - top():
                - return main.top()
          - getMin():
                - return min.top()
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }
    
    void pop() {
        if(st.top() == minSt.top())
            minSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

// Time : O(1) for all operations
// Space : O(n)
