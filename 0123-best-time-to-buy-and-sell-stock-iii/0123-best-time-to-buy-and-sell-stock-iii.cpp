#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // --- YE APNE SYSTEM KA GENERATED LOGIC HAI ---
        int buy1 = INT_MAX;
        int profit1 = 0;
        int buy2 = INT_MAX;
        int profit2 = 0;

        for (int p : prices) {
            buy1 = std::min(buy1, p);
            profit1 = std::max(profit1, p - buy1);
            buy2 = std::min(buy2, p - profit1);
            profit2 = std::max(profit2, p - buy2);
        }

        return profit2;
        // ---------------------------------------------
    }
};