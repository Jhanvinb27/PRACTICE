Ques : Given an array numbers.
       The array is already sorted in non decreasing order.
       Let these two numbers be numbers[index1] and numbers[index2] 
       where 1 <= index1 < index2 <= numbers.length.
       Return the indices of the two numbers, index1 and index2, 
       added by one as an integer array [index1, index2] of length 2.

  // leetcode link - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

# include <bits/stdc++.h>
using namespace std;

vector <int> TwoSumII (vector<int>& nums, int target){
  int l = 0;
  int r = nums.size() - 1;
  while(nums[l] + nums[r] != target){
    if(nums[l] + nums[r] < target){
      ++l;
    } else {
      --r;
    }
  }
  return {l+1,r+1};
}

int main(){
  vector<int> nums = [2,7,11,15];
  int target = 13;
  TwoSumII(nums,target);
  return 0;
}
