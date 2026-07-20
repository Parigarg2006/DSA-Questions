#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * Calculates the maximum profit from stock trading with a one-day cooldown.
     * Uses a state machine approach with three states:
     * - hold: Currently holding a stock.
     * - sold: Just sold a stock (must enter cooldown next).
     * - rest: Not holding a stock and not in cooldown (can buy).
     */
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        // Initial states for day 0
        int hold = -prices[0]; // Bought on day 0
        int sold = 0;          // Cannot sell on day 0
        int rest = 0;          // No stock held

        for (size_t i = 1; i < prices.size(); ++i) {
            int prev_hold = hold;
            int prev_sold = sold;
            int prev_rest = rest;

            // Can hold by keeping previous hold or buying after a rest
            hold = std::max(prev_hold, prev_rest - prices[i]);
            
            // Can sell only if we were holding
            sold = prev_hold + prices[i];
            
            // Can rest by staying in rest or coming from a sold state
            rest = std::max(prev_rest, prev_sold);
        }

        // Max profit is either having sold or resting
        return std::max(sold, rest);
    }
};