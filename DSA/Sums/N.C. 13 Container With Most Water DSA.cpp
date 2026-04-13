/*
Ques - You are given an integer array height of length n. 
     - There are n vertical lines drawn such that the two endpoints of the 
     - ith line are (i, 0) and (i, height[i]).
     - Find two lines that together with the x-axis form a container, 
     - such that the container contains the most water.
     - Return the maximum amount of water a container can store.
     - Notice that you may not slant the container.
*/
/*
Example 1 - Input: height = [1,8,6,2,5,4,8,3,7]
          - Output: 49
          - Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
            In this case, the max area of water (blue section) the container can contain is 49.

Example 2 - Input: height = [1,1]
          - Output: 1
*/
/*
Approach 1 - try all pairs (i, j) where i < j
           - calculate:
                        width = j - i
                        height = min(height[i], height[j])
                        area = width * height
           - keep track of the maximum area
Algorithm - initialize maxArea = 0
          - loop i from 0 to n-1
          - loop j from i+1 to n-1
          - for each pair:
          - width = j - i
          - height = min(height[i], height[j])
          - area = width * height
          - update maxArea = max(maxArea, area)
          - return maxArea
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int width = j - i;
                int h = min(height[i], height[j]);
                int area = width * h;
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
// Time : O(n^2)
// Spcae : O(1)

/*
Approach - Start with two pointers:
                - left = 0
                - right = n - 1
        - this gives the maximum width initially
        - area = (right - left) * min(height[left], height[right])
Algorithm - initialize:
                - left = 0, right = n - 1
                - maxArea = 0
          - while left < right:
                - width = right - left
                - h = min(height[left], height[right])
                - area = width * h
          - update maxArea
          - if height[left] < height[right]:
                - left++
                - else:
                - right--
          - return maxArea
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width * h;
            maxArea = max(maxArea, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxArea;
    }
};

// Time : O(n)
// Space : O(1)
