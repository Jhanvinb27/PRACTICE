/*
Ques - Koko loves to eat bananas. There are n piles of bananas,
     - the ith pile has piles[i] bananas.
     - The guards will come back in h hours.
     - Koko can decide her eating speed k (bananas per hour).
     - Each hour, she chooses one pile and eats k bananas.
     - If pile < k → she eats all and still spends 1 hour.
     - Return the minimum integer k such that she can eat all bananas within h hours.
*/

/*
Example 1 - Input: piles = [3,6,7,11], h = 8
          - Output: 4

Example 2 - Input: piles = [30,11,23,4,20], h = 5
          - Output: 30

Example 3 - Input: piles = [30,11,23,4,20], h = 6
          - Output: 23
*/

/*
Observation -
- Eating speed k ranges from 1 → max(piles)
- If k increases → total hours decreases
- If k decreases → total hours increases
- This is a monotonic function → perfect for binary search
- Time to eat a pile = ceil(pile / k) = (pile + k - 1) / k :contentReference[oaicite:0]{index=0}
*/

/*
Approach 1 - Brute Force
           - Try every possible k from 1 to max(piles)
           - For each k, calculate total hours

Algorithm -
          - for k = 1 to max(piles):
                - compute totalHours
                - if totalHours <= h:
                        - return k
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());

        for(int k = 1; k <= maxPile; k++){
            long long hours = 0;

            for(int pile : piles){
                hours += (pile + k - 1) / k;
            }

            if(hours <= h)
                return k;
        }

        return maxPile;
    }
};

// Time : O(n * max(piles))
// Space : O(1)

/*
Approach 2 - Optimal (Binary Search on Answer)
           - Search k in range [1, max(piles)]
           - Use helper to check if a speed is valid

Intuition -
- If a speed k works → all higher speeds also work
- If k fails → all smaller speeds fail
- So find the minimum valid k using binary search :contentReference[oaicite:1]{index=1}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left <= right){
            int mid = left + (right - left) / 2;

            long long hours = 0;
            for(int pile : piles){
                hours += (pile + mid - 1) / mid;
            }

            if(hours <= h)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};

// Time : O(n log max(piles))
// Space : O(1)
// binary search the minimum eating speed where total hours ≤ h.
// Binary Search on Answer
// Monotonic function (valid → always valid after)
