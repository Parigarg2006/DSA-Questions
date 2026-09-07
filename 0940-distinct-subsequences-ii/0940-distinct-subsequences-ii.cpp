class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        vector<long long> last(26, 0);

        long long dp = 1;  // includes empty subsequence

        for (char c : s) {
            int index = c - 'a';

            long long newDp = (2 * dp) % MOD;

            newDp = (newDp - last[index] + MOD) % MOD;

            last[index] = dp;

            dp = newDp;
        }

        // Remove empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};