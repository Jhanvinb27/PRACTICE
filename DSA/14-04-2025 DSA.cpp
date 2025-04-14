// DSA Questions, approach, learnings
/*
Ques - https://neetcode.io/problems/two-integer-sum

Approach:
  - Given:
      - array - int : nums
      - int : target
      - return indices i & j
      - Condition :
          - nums[i] + nums[j] == target
          - i != j

  - Assumption:
      - every target can be formed by only 1 pair of i and j

  - Solution 1: 
    - n is the number of elements in the given array nums.
      - I'll select an element at 0th index and from there, I'll check for every single element if that matches target:
        i.e (0th ele + 1st ele) , (0th ele + 2nd ele) , (0th ele + 3rd ele) , ... , (0th ele + n-1 ele) if not found then
            (1st ele + 2nd ele) , (1st ele + 3rd ele) , (1st ele + 4th ele) , ... , (1st ele + n-1 ele) again not found then
            (2nd ele + 3rd ele) , (2nd ele + 4th ele) , ... , (2nd ele + n-1 ele) 
            ...
            ...
            ...  if still not found then in worst case
            (n-2 ele + n-1 ele) will be the answer.

    - Let's code it:
*/
# include <bits/stdc++.h>
using namespace std;
  vector <int> TwoSum (vector<int> nums, int target) {
      int n = nums.size();
      for (int i = 0; i < n; i++) {
          for (int j = i+1; j < n; j++) {
              if ((nums[i] + nums[j]) == target && i !=j) {
              cout << i << " " << j << endl;
              } 
          }
      }
      return{};
  }
  int main() {
      vector<int> nums = {3,4,5,6};
      int target = 7;
      TwoSum(nums, target);
      return 0;
  }

//LeetCode Ques - https://leetcode.com/problems/two-sum/
//LeetCode Solution :
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
          for (int j = i+1; j < n; j++) {
              if ((nums[i] + nums[j]) == target && i !=j) {
                return {i,j};
              }  
            }
        }
    return{};
    }
};
/*
Complexity analysis:
  - 1st for loop runs O(n) times as there are n elements in the array from i = 0  to i = n-1
  - 2nd for loop runs O(n-1) times as for this one there will always be 1 element less to check from j = i+1 to j = n-1.
  - Total Time Complexity : O(n) * O (n-1) ~ O(n^2)
  - Space Complexity : no extra space is used, just travelsal : O(1)
*/

//Optimal Approach ... yet to think
