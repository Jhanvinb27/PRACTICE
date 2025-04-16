/*
Ques - https://neetcode.io/problems/duplicate-integer
Approach :
  - Given:
      -  an int array nums
      - return true if any element of the array appears more than once
      - else return false

      - check if any element is occuring more than once in the array
Solution 1 :
      - I'll sort the array first O(n log n)
      - then i'll use a for loop to iterate through the array and whenever i encounter the number O(n)
        and the coressponding number is equal then, 
        i'll increase the count.
      - then, i'll simply return true and if not encountered then false.
  */
# include <iostream>
using namespace std;
bool hasDuplicate(vector<int>& nums) {
  int n = nums.size();
  sort(nums.begin(),nums.end());
  for (int i = 1; i < n; i++){
      if (nums[i] == nums[i-1]){ 
        return true;
      }
  }
  return false;
}

// Time Complexity : O(nlog n)
// Space Complexity : O(1)

/*
Solution 2 :
  - we'll run two loops
  - outer loop: pick a number at position i.
  - inner loop: compare that number with all numbers after it (starting at j = i + 1).
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
};
// Time Complexity : O(n^2)
// Space Complexity : O(1)

/*
Solution 3 :
  - I'll maintain an unordered set to track the number with - whether it's seen or not.
  - we'll run a for loop to traverse all the elements through the array
  - and if the count of any element in set exceeeds 0 it means it's a duplicate
  - else we'll simpy insert it in set and return false
  - unordered_set will store <int>
*/
# include <bits/stdc++.h>
using namespace std;
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums) {
            if (set.count(num) > 0)
                return true;
            set.insert(num);
        }
        return false;
    }
// Time Complexity : O(n)
// Space Complexity : O(n)

/*
Solution 4 :
  - we'll use a hash map
*/
# include <bits/stdc++.h>
using namespace std;
 bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int num : nums) {
            if (seen[num] >= 1)
                return true;
            seen[num]++;
        }
        return false;
    }
// Time Complexity : O(n)
// Space Complexity : O(n)

/*
Solution 5:
  - LeetCode Discussion Solution
*/
# include <bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end()); // This line creates an unordered_set from the vector nums.
                                                            // unordered_set stores only unique elements.
                                                          // nums.begin() and nums.end() define the range of elements to insert.
                                                        // If nums has duplicates, those values will only be inserted once in the set.
                                                      // nums = {1, 2, 2, 3} -> numSet = {1, 2, 3}  // duplicates are dropped
        return numSet.size() < nums.size();//If the size of the set is smaller than the original vector, 
                                          //it means some values were duplicates.
                                        //So:
                                      //If duplicate exists → set size is smaller → returns true.
                                    // If no duplicates → set size equals vector size → returns false.        
    }

// Time Complexity : O(n)
// Space Complexity : O(n)


/*
Solution 6:
  - Mayank's Solution with ChatGPT
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Assume input values are in range [0, 100000]
        const int MAX_VALUE = 100001;
        vector<int> freq(MAX_VALUE, 0); // Initialize array with all 0s

        for (int num : nums) {
            freq[num]++; // Increase the count for this number

            if (freq[num] > 1) {
                return true; // Duplicate found
            }
        }

        return false; // No duplicates
    }
};
// Time Complexity : O(n)
// Space Complexity : O(k)
         // k is the size of the range of numbers.
        // In this case, O(100001) = effectively O(1) if the range is known and small.
