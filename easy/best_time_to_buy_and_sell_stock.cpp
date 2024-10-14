// Leetcode problem: 121. Best Time to Buy and Sell Stock
// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0; // EDGE CASE -> empty input

        // First find the smallest int -> using that price as the starting point -> go through the rest of the prices and find the biggest one
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};