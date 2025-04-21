/*
Ques - https://neetcode.io/problems/longest-consecutive-sequence
*/
/*
Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.
A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. 
The elements do not have to be consecutive in the original array.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [2,20,4,10,3,4,5]
Output: 4
Explanation: The longest consecutive sequence is [2, 3, 4, 5].

Example 2:
Input: nums = [0,3,2,5,4,6,1,1]
Output: 7

Constraints:
0 <= nums.length <= 1000
-10^9 <= nums[i] <= 10^9
*/

/*
Approach - Given an array, in any order, with a list of integers
         - we have to return an INT that shows the length of longest consecutive sequence
         - the numbers can be jumbeled
         - we have to check that any number must be exactly 1 greater than previous element (of output array)
*/

/*
Sulution 1 - wee'll store all the elements in a map or a set in ascending order
           - we'll intizialie an int counter = 0
           - then put the condition that if in the map or set if the next element is exactly +1 then the prev one
           - then counter ++
           - return the counter.
           - Let's code it
*/

#include <bits/stdc++.h>
using namespace std;

int LongestConsecutiveSubsequence(vector<int> nums) {
    unordered_set<int> s;
    // insert all elements into the set
    for (int num : nums) {
        s.insert(num);
    }
    int longest = 0;
    for (int num : nums) {
        if (s.find(num - 1) == s.end()) { // if the number just before num is NOT in the set..
            int currentNum = num;
            int count = 1;

            while (s.find(currentNum + 1) != s.end()) { // as long as the next number (currentNum + 1) exists in the set s, keep going
                currentNum++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}

int main() {
    vector<int> nums = {2, 20, 4, 10, 3, 4, 5};
    cout << LongestConsecutiveSubsequence(nums);
    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

// sorting based taken O( n log n)

#include <bits/stdc++.h>
using namespace std;

int LongestConsecutiveSubsequence(vector<int> nums) {
    if (nums.empty()) return 0;

    sort(nums.begin(), nums.end()); // Step 1: Sort the array

    int longest = 1;
    int count = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            continue; // Skip duplicates
        }
        else if (nums[i] == nums[i - 1] + 1) {
            count++; // Part of a sequence
        } else {
            longest = max(longest, count); // Save max so far
            count = 1; // Reset for new sequence
        }
    }

    longest = max(longest, count); // Final check
    return longest;
}

int main() {
    vector<int> nums = {9, 56, 53, 8, 0, 4, 55, 78, 3, 54, 2, 0, 1, 57};
    cout << LongestConsecutiveSubsequence(nums);
    return 0;
}










