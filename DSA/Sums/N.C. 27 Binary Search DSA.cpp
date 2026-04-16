/*
Ques - Given an array of integers nums which is sorted in ascending order,
     - and an integer target,
     - return the index of target if found,
     - otherwise return -1.
     - You must write an algorithm with O(log n) runtime complexity. :contentReference[oaicite:0]{index=0}
*/

/*
Example 1 - Input: nums = [-1,0,3,5,9,12], target = 9
          - Output: 4

Example 2 - Input: nums = [-1,0,3,5,9,12], target = 2
          - Output: -1
*/

/*
Observation -
- Array is sorted → key property
- Linear search → O(n)
- We can eliminate half search space every step
- This leads to logarithmic complexity
*/

/*
Approach 1 - Brute Force
           - Traverse entire array
           - Check if element equals target

Algorithm -
          - for i from 0 to n-1:
                - if nums[i] == target:
                        - return i
          - return -1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target)
                return i;
        }
        return -1;
    }
};

// Time : O(n)
// Space : O(1)

/*
Approach 2 - Optimal (Binary Search)
           - Use two pointers: left and right
           - Repeatedly divide search space

Intuition -
- Compare target with middle element
- If equal → found
- If target smaller → search left half
- If target greater → search right half
- Each step reduces search space by half :contentReference[oaicite:1]{index=1}
*/

/*
Algorithm -
          - initialize left = 0, right = n-1
          - while left <= right:
                - mid = left + (right - left) / 2
                - if nums[mid] == target:
                        - return mid
                - else if nums[mid] < target:
                        - left = mid + 1
                - else:
                        - right = mid - 1
          - return -1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};

// Time : O(log n)
// Space : O(1)
