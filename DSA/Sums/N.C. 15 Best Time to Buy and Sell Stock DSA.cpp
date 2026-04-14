/*
Ques - You are given an array prices where prices[i] is the price of a stock on day i.
     - You want to maximize your profit by choosing:
            - one day to buy
            - one future day to sell
     - Return the maximum profit.
     - If no profit is possible, return 0.
*/

/*
Example 1 - Input: prices = [7,1,5,3,6,4]
          - Output: 5
          - Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6)
            Profit = 6 - 1 = 5 :contentReference[oaicite:0]{index=0}

Example 2 - Input: prices = [7,6,4,3,1]
          - Output: 0
          - Explanation: Prices are decreasing, so no profit is possible :contentReference[oaicite:1]{index=1}
*/

/*
Approach 1 - Try all pairs (i, j) where i < j
           - Treat i as buy day, j as sell day
           - profit = prices[j] - prices[i]
           - keep track of maximum profit

Algorithm - initialize maxProfit = 0
          - loop i from 0 to n-1
          - loop j from i+1 to n-1
          - profit = prices[j] - prices[i]
          - update maxProfit = max(maxProfit, profit)
          - return maxProfit
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};

// Time : O(n^2)
// Space : O(1)

/*
Approach - Track minimum price so far (best day to buy)
         - At each day, calculate profit if sold today
         - Keep updating maximum profit

Algorithm - initialize:
                - minPrice = prices[0]
                - maxProfit = 0
          - loop i from 1 to n-1:
                - update minPrice = min(minPrice, prices[i])
                - profit = prices[i] - minPrice
                - update maxProfit = max(maxProfit, profit)
          - return maxProfit
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};

// Time : O(n)
// Space : O(1)
