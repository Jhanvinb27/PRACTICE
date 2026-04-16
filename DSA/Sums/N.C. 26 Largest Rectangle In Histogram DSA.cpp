/*
Ques - Given an array of integers heights representing the histogram's bar height
     - where the width of each bar is 1,
     - return the area of the largest rectangle in the histogram.
*/

/*
Example 1 - Input: heights = [2,1,5,6,2,3]
          - Output: 10

Example 2 - Input: heights = [2,4]
          - Output: 4
*/

/*
Observation -
- Rectangle area = height * width
- Width depends on how far a bar can extend left & right
- A bar can extend until we find a smaller height
- Brute force → expand left & right for every bar
- Optimal → find nearest smaller elements using stack
*/

/*
Approach 1 - Brute Force
           - Treat each bar as the smallest height
           - Expand left and right until smaller bar found

Intuition -
- Each bar acts as limiting height
- Find maximum width where all bars ≥ current bar :contentReference[oaicite:0]{index=0}
- Compute area for every bar and take maximum

Algorithm -
          - for i from 0 to n-1:
                - height = heights[i]
                - expand left while heights >= height
                - expand right while heights >= height
                - width = right - left + 1
                - area = height * width
                - update maxArea
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            int h = heights[i];
            int left = i, right = i;

            while(left >= 0 && heights[left] >= h) left--;
            while(right < n && heights[right] >= h) right++;

            int width = right - left - 1;
            int area = h * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// Time : O(n^2)
// Space : O(1)

/*
Approach 2 - Optimal (Monotonic Stack)
           - Use increasing stack (store indices)
           - Find nearest smaller element on left & right

Intuition -
- Each bar wants to expand maximum width
- Stack helps find boundaries efficiently
- When current bar is smaller → previous bars cannot extend further :contentReference[oaicite:1]{index=1}

Algorithm -
          - initialize empty stack
          - for i from 0 to n:
                - while stack not empty AND current height < height at stack top:
                        - pop index
                        - height = popped bar height
                        - width = i if stack empty else i - stack.top() - 1
                        - update maxArea
                - push i
          - return maxArea
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i <= n; i++){
            int currHeight = (i == n) ? 0 : heights[i];

            while(!st.empty() && currHeight < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();

                int width;
                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};

// Time : O(n)
// Space : O(n)
