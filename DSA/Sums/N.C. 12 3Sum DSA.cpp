/*
Ques - Given an integer array nums, return all the unique triplets [nums[i], nums[j], nums[k]] such that:
     - nums[i] + nums[j] + nums[k] == 0
     - Constraint:
           - 0 ≤ i, j, k < n
           - i ≠ j ≠ k
           - The solution set must not contain duplicate triplets
*/
/*
Example - Input : nums = [-1, 0, 1, 2, -1, -4]
        - Output : [[-1, -1, 2], [-1, 0, 1]]
*/
/*
Approach - sort the array
         - iterate i from 0 to n-3
         - skip duplicates for i
         - set l = i+1, r = n-1
         - while l < r:
               - compute sum = nums[i] + nums[l] + nums[r]
               - if sum == 0 → store triplet, move both pointers
               - skip duplicates for l and r
               - if sum < 0 → l++
               - if sum > 0 → r--
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i + 2 < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return ans;
    }
};

// Time : O(n^2) (outer loop(O(n) + two-pointer(O(n))))
// Space : O(1)  (excluding output)
