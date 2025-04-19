/*
Ques - https://neetcode.io/problems/products-of-array-discluding-self

Given an integer array nums, return an array output where output[i] 
is the product of all the elements of nums except nums[i].
Each product is guaranteed to fit in a 32-bit integer.

Example 1:
Input: nums = [1,2,4,6]
Output: [48,24,12,8]

Example 2:
Input: nums = [-1,0,1,2,3]
Output: [0,-6,0,0,0]

Constraints:
2 <= nums.length <= 1000
-20 <= nums[i] <= 20
*/

/*
Approach - given is an array of nums
         - return an array of integers
           - which as the product of all the numbers in the array 
             except the one which has the same index as of the answer in nums
*/

/*
Solution 1 - we can create an output array which will store the numbers such that
           - the res[i] = multiplication of all the numbers in the array/nums[i]
           i.e res[1] = mul. of all numbers in the input array/nums[i]
           - Let's code it
*/

# include <bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf (vector<int>& nums){
  int n = nums.size();
  vector<int> output(n);
  int result = 1;
  for(int i = 0; i < n; i++) {
    result = result * nums[i];
  }
  for (int i =0; i < n; i++){
        output[i] = result / nums[i];
  }
  return output;
}
// But this won't work as it will crash when it encounteers 0.
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> output(n);
    int result = 1;
    int zeroCount = 0; 
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            zeroCount++;
            continue;
        }
        result = result * nums[i];
    }
    for (int i = 0; i < n; i++) {
        if (zeroCount > 1) {
            output[i] = 0; 
        } else if (zeroCount == 1) {
            if (nums[i] == 0) {
                output[i] = result; 
            } else {
                output[i] = 0;
            }
        } else {
            output[i] = result / nums[i];
        }
    }
    return output;
}
// Time Complexity : O(n)
// Space Complexity : O(n)

// To avoid cal. 0
// we cal. left of i and right of i seperately
vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        vector<int> right(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        vector<int> output(n);
        for (int i = 0; i < n; i++) {
            output[i] = left[i] * right[i];
        }
        return output;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(n)

// first we will store product of all elements to the left of i
// then we will multiply by product of all elements to the right of i
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> output(n);
  
    output[0] = 1;
    for (int i = 1; i < n; i++) {
        output[i] = output[i - 1] * nums[i - 1];
    }
    
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        output[i] = output[i] * right;
        right = right * nums[i];
    }
    return output;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

