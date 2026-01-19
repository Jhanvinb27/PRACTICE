/*
Given - Given an array of integers nums, 
Return - INT
       - the length of the 
       - longest consecutive sequence of elements that can be formed

A consecutive sequence is a sequence of elements in which each element is 
exactly 1 greater than the previous element. 
The elements do not have to be consecutive in the original array.
*/

#include <bits/stdc++.h>
using namespace std;
int LCS(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());
    int longest = 1;
    int current = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            continue;
        }
        else if (nums[i] == nums[i - 1] + 1) {
            current++;
        }
        else {
            longest = max(longest, current);
            current = 1;
        }
    }
    longest = max(longest, current);
    return longest;
}
//Time: O(n log n) (sorting)
//Space: O(1) (ignoring sort stack)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for (int num : s) {
            if (s.find(num - 1) == s.end()) {
                int current = num;
                int count = 1;
                while (s.find(current + 1) != s.end()) {
                    current++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
//Time Complexity: O(n)
//Space Complexity: O(n)
