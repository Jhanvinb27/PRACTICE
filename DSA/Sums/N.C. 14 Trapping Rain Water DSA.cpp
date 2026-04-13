/*
Ques - You are given an integer array height of length n.
     - Each element represents the height of a bar.
     - After raining, water can be trapped between the bars.
     - Return the total amount of water that can be trapped.
*/

/*
Example 1 - Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
          - Output: 6

Example 2 - Input: height = [4,2,0,3,2,5]
          - Output: 9
*/

/*
Approach 1 - For each index, find left max and right max
           - water[i] = min(leftMax, rightMax) - height[i]

Algorithm - initialize water = 0
          - loop i from 0 to n-1
          - find leftMax from 0 to i
          - find rightMax from i to n-1
          - water += min(leftMax, rightMax) - height[i]
          - return water
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;

        for (int i = 0; i < n; i++) {
            int leftMax = 0, rightMax = 0;

            for (int j = 0; j <= i; j++)
                leftMax = max(leftMax, height[j]);

            for (int j = i; j < n; j++)
                rightMax = max(rightMax, height[j]);

            water += min(leftMax, rightMax) - height[i];
        }

        return water;
    }
};

// Time : O(n^2)
// Space : O(1)

/*
Approach - Use two pointers with leftMax and rightMax
         - water depends on the smaller side

Algorithm - initialize:
                - left = 0, right = n - 1
                - leftMax = 0, rightMax = 0
                - water = 0
          - while left <= right:
                - if height[left] <= height[right]:
                        - if height[left] >= leftMax:
                                - update leftMax
                        - else:
                                - water += leftMax - height[left]
                        - left++
                - else:
                        - if height[right] >= rightMax:
                                - update rightMax
                        - else:
                                - water += rightMax - height[right]
                        - right--
          - return water
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left];
                left++;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right];
                right--;
            }
        }

        return water;
    }
};

// Time : O(n)
// Space : O(1)
