/*
Ques - You are given an array of integers nums and an integer k.
     - There is a sliding window of size k which moves from left to right.
     - Return the maximum element in each window.
*/

/*
Example 1 - Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
          - Output: [3,3,5,5,6,7]

Example 2 - Input: nums = [1], k = 1
          - Output: [1]
*/

/*
Observation -
- Window size is fixed (k)
- For each window, we need the maximum element
- Brute force recalculates max every time → inefficient
- We need a structure that keeps track of max efficiently
*/

/*
Approach 1 - Check each window
           - For every window of size k, find max by iterating

Intuition -
- Slide window one step at a time
- For each window, compute max independently
- Simple but repeats work

Algorithm - initialize result vector
          - loop i from 0 to n-k
          - find max in range [i, i+k-1]
          - push max into result
          - return result
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i <= n - k; i++) {
            int maxi = nums[i];
            for (int j = i; j < i + k; j++) {
                maxi = max(maxi, nums[j]);
            }
            res.push_back(maxi);
        }

        return res;
    }
};

// Time : O(n * k)
// Space : O(1)

/*
Approach - Deque (Monotonic Decreasing Queue)
         - Store indices in deque
         - Maintain decreasing order of values
         - Front always contains max of window

Intuition -
- Remove elements smaller than current → useless
- Remove elements out of window
- Keep only useful candidates for max

Algorithm - initialize deque dq and result vector
          - loop i from 0 to n-1:
                - remove indices out of window (i-k)
                - while dq not empty AND nums[dq.back()] < nums[i]:
                        - pop_back
                - push current index
                - if i >= k-1:
                        - result.push_back(nums[dq.front()])
          - return result
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

// Time : O(n)
// Space : O(k)
