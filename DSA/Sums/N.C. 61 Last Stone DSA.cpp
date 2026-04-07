/*
Ques - https://leetcode.com/problems/last-stone-weight/description/

You are given an array of integers stones 
where stones[i] is the weight of the ith stone.
We are playing a game with the stones. 
On each turn, we choose the heaviest two stones and smash them together. 
Suppose the heaviest two stones have weights x and y with x <= y. 
The result of this smash is:
      - If x == y, both stones are destroyed, and
      - If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.
*/
/*
Example 1:
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

Example 2:
Input: stones = [1]
Output: 1
*/
/*
Approach 1 - sort array
           - subract [highest - second highest]
           - remove both the last elements
           - now the resulting difference those 2 elements add them back in array
           - insert it back in the sorted array exactly at the place where the sorting is not required
           - repeat this until there's only 1 element left in the array

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
    sort(arr.begin(), arr.end()); //O(n log n)

    while(arr.size() > 1) { // runs O(n-1) times ~ O(n) 
        int n = arr.size();

        int a = arr[n - 1]; // O(1)
        int b = arr[n - 2]; // O(1)

        arr.pop_back();
        arr.pop_back();  // O(1)

        int val = a - b; 

        auto it = lower_bound(arr.begin(), arr.end(), val); // O(log n)
        arr.insert(it, val); // O(n)
    }

    return arr[0];
}
// T.C - O(n^2)
// S.C - O(1)
/*
Approach -  1. We put all the stones into a special box  
               - this box always lets us pick the heaviest stone instantly

            2. Then we repeat this process:
                - Take the two heaviest stones  
                - Smash them together

            3. After smashing:
               - If both stones are equal → they both break and disappear  
               - If they are different → the heavier one survives, but becomes lighter  
                 (new weight = difference)

            4. Put the remaining stone (if any) back into the box

            5. Keep doing this until:
               - Only one stone remains, or  
               - No stones are left

              - If one stone is left → return its weight  
              - If none are left → return 0

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end()); //O(n)

        while(pq.size() > 1){
            int x = pq.top(); pq.pop();  // O(log n)
            int y = pq.top(); pq.pop();  // O(log n)

            if(x != y){
                pq.push(x - y);
            }
        }
        if(pq.size() == 1) return pq.top();
        return 0;
    }
};
// T.C - O(n log n)
// S.C - O(n)
*/
