/*
Given -  an array of integers numbers that is sorted in non-decreasing order.
Return - return the indices (1-indexed) of two numbers, [index1, index2]

- such that they add up to a given target number 
- target and index1 < index2. 
- Note that index1 and index2 cannot be equal, 
  therefore you may not use the same element twice.
- There will always be exactly one valid solution.
- Your solution must use O(1) additional space.
*/  

# include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1};
            }
            else if (sum < target) {
                i++;
            }
            else {
                j--;
            }
        }
        return {};
    }
int main() {
    vector<int> nums = {1, 2, 3, 4};
    int target = 3;
    vector<int> ans = twoSum(nums, target);
    cout << "[" << ans[0]  << "," <<  ans[1] << "]";
    return 0;
}

//Time Complexity - O(n)
//Each pointer (i and j) moves at most n times.
// Space Complexity - O(1)
