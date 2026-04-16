/*
Ques - Given an array of integers temperatures represents the daily temperatures,
     - return an array answer such that answer[i] is the number of days
     - you have to wait after the ith day to get a warmer temperature.
     - If there is no future day for which this is possible, keep answer[i] = 0.
*/

/*
Example 1 - Input: temperatures = [73,74,75,71,69,72,76,73]
          - Output: [1,1,4,2,1,1,0,0]

Example 2 - Input: temperatures = [30,40,50,60]
          - Output: [1,1,1,0]

Example 3 - Input: temperatures = [30,60,90]
          - Output: [1,1,0]
*/

/*
Observation -
- For each day, we need the next greater temperature
- Brute force → check all future days
- We need a faster way → avoid repeated comparisons
- This is a "Next Greater Element" pattern
- Stack helps track unresolved days efficiently :contentReference[oaicite:0]{index=0}
*/

/*
Approach 1 - Brute Force
           - For each day, check all next days
           - Stop when warmer temperature is found

Algorithm -
          - initialize result array with 0
          - for i from 0 to n-1:
                - for j from i+1 to n-1:
                        - if temperatures[j] > temperatures[i]:
                                - result[i] = j - i
                                - break
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(temperatures[j] > temperatures[i]){
                    res[i] = j - i;
                    break;
                }
            }
        }

        return res;
    }
};

// Time : O(n^2)
// Space : O(1)

/*
Approach 2 - Optimal (Monotonic Stack)
           - Use stack to store indices of unresolved days
           - Maintain decreasing temperatures in stack

Intuition -
- We only care about days that haven't found a warmer day yet
- When a warmer temperature comes:
        - resolve all previous smaller temperatures
- Each element is pushed and popped once → O(n) :contentReference[oaicite:1]{index=1}

Algorithm -
          - initialize result array with 0
          - create empty stack (store indices)
          - for i from 0 to n-1:
                - while stack not empty AND temperatures[i] > temperatures[stack.top()]:
                        - idx = stack.top()
                        - pop stack
                        - result[idx] = i - idx
                - push i into stack
          - return result
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int idx = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }

        return res;
    }
};

// Time : O(n)
// Space : O(n)
