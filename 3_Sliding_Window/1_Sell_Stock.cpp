/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing 
a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*
Solution: Sliding window approach

Complexity analysis:
    - Time complexity: O(n) - beats 77.73%
    - Space complexity: O(1) - beats 11.52%
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < buy_price) buy_price = prices[i];
            max_profit = max(max_profit, prices[i] - buy_price);
        }
        return max_profit;
    }
};