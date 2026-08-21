class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long countNumbers(long long x, vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        // Try every subset of coins
        for (int mask = 1; mask < (1 << n); mask++) {

            long long currentLCM = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    bits++;

                    currentLCM = lcm(currentLCM, coins[i]);

                    // If LCM becomes bigger than x,
                    // there are no multiples <= x.
                    if (currentLCM > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long long ways = x / currentLCM;

            // Odd number of selected coins -> add
            if (bits % 2 == 1)
                count += ways;

            // Even number -> subtract
            else
                count -= ways;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, long long k) {

        long long low = 1;

        // The answer cannot be greater than
        // smallest coin * k.
        long long minCoin = *min_element(coins.begin(), coins.end());

        long long high = minCoin * k;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (countNumbers(mid, coins) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};