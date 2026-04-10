/*
Ques - Given an unsorted array of integers nums and an integer k, 
return the kth largest element in the array.
By kth largest element, we mean the kth largest element in the sorted order, 
not the kth distinct element.
Follow-up: Can you solve it without sorting?
*/

/*
Approach - sort
         - return [n-k[
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // O(n log n)
        int n = nums.size();
        return nums[n - k];
    }
};
// Time Complexity - O(n log n)
// Space Complexity - O( log n)
// If we ignore recursion stack, it can be considered O(1) auxiliary space.

/*
Approach - initialize a priority queue
         - push nums in pq
         - Remove k-1 Largest Elements
         - repeat (k - 1) times:
         - remove the top element from the heap
         - remove the biggest element k-1 times, and the next top is your answer
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue <int> pq;

       for(auto it:nums) {
        pq.push(it);
       }

       while(k-1 > 0){
        pq.pop();
        k--;
       }
       return pq.top();
    }
};
// Time Complexity : O((n + k) log n)
// Space Complexity : O(n)
