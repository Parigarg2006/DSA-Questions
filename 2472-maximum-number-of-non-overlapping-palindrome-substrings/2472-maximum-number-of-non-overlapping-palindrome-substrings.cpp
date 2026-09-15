class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Every single character is a palindrome
        for (int i = 0; i < n; i++) {
            pal[i][i] = true;
        }

        // Check substrings by increasing length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len == 2) {
                        pal[i][j] = true;
                    }
                    else {
                        pal[i][j] = pal[i + 1][j - 1];
                    }
                }
            }
        }

        // dp[i] = maximum number of valid palindromes
        // using first i characters
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Don't take a palindrome ending at i-1
            dp[i] = dp[i - 1];

            // Try every possible starting position
            for (int j = 0; j < i; j++) {

                int len = i - j;

                if (len >= k && pal[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};