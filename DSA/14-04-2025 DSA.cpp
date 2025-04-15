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
              if ((nums[i] + nums[j]) == target && i !=j) { // unecessary condition
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
  - 2nd for loop runs O(n) times as for this one there will always be 1 element less to check from j = i+1 to j = n-1.
*/
// Total Time Complexity : O(n) * O (n-1) ~ O(n^2)
// Space Complexity : no extra space is used, just travelsal : O(1)

/* 
Solution 2:
  - sorting will take O(n log n) 
  - as we'll use two pointers - one from left i.e smallest number and one from right i.e larget number
  - this will take O(n) time as each number is only visited once
  - we'll move left inwards if res > nums at left ptr + nums at right ptr
  - else we'll move right pointer inwards if res < nums at left ptr + nums at right ptr
  - but in order to return correct indicies we need an additional array to store the orginal indices of numbers 
    as after sorting, they'll be jumbled. (takes O(n) time)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
         // store number along with its original index
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < n; i++) {
            numWithIndex.push_back({nums[i], i});
        }
        // sort based on the number value
        sort(numWithIndex.begin(), numWithIndex.end());
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = numWithIndex[left].first + numWithIndex[right].first;
            if (sum == target) {
                return {numWithIndex[left].second, numWithIndex[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {}; 
    }
};
// Total Time Complexity : O(n)+O(n log n)+O(n) = O(n log n)
// Space Complexity : O(n) for storing the original indices array


//OPTIMAL AND DESIRED
/*
Solution 3:
  - nums[i] represents the ith element in nums 
  - we will subtract target from nums and store the result for each nums in a hashmap
    i.e res = target - nums[i];
  - then we will store the element of nums and it's index in a [key,value] pair in our hashmap.
  - for every res, we will remember the element in our hashmap, and 
    if res == nums[i] which is already recorderd in our map then we will simply return {Map[res],i}.
  - according to the question, there exists only 1 unique solution
  - therefore only one value for the res that will be matching in nums.

  - Let's code it
  */
# include <bits/stdc++.h>
using namespace std;
vector<int> twoSum (vector<int>& nums, int target) {
  int n = nums.size();
  unordered_map <int,int> Map;
  int i =0;
  int res =0;
  for (int i = 0; i < n; i++) {
    res = target - nums[i];
    if (Map.find(res) != Map.end() && i != Map[res]){
      return {Map[res],i};
    }
    Map[nums[i]]=i;
  }  
  return {};
}
int main () {
  vector<int> nums = {3,4,5,6};
  int target = 7;
  twoSum (nums, taregt);
  return 0;
}
// Leetcode solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map <int,int> map;
        int i = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = target - nums[i];
            if(map.find(res) != map.end() && i != map[res]){
                return {map[res],i};
            }
            map[nums[i]] = i;
        }
    return{};
    }
};

// Time Complexity : O(n)
//                 because in worst case we'll look ant each and every number to match with res
// Space Complexity : O(n)
//                 because we are storing each and every element
//                 therefore, suppode there are total n elements in the array then we'll also require 'n' units of space to store them

