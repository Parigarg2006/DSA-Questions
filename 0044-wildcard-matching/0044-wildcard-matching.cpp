#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[j] represents whether s[0...i-1] matches p[0...j-1]
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        // Base case: patterns like "*", "***" can match an empty string
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[j] = dp[j - 1];
            }
        }
        
        for (int i = 1; i <= m; ++i) {
            vector<bool> next_dp(n + 1, false);
            // An empty pattern cannot match a non-empty string
            next_dp[0] = false;
            
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // '*' can match empty sequence (next_dp[j-1]) or sequence of characters (dp[j])
                    next_dp[j] = next_dp[j - 1] || dp[j];
                } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    // '?' or exact character match depends on the previous state
                    next_dp[j] = dp[j - 1];
                } else {
                    next_dp[j] = false;
                }
            }
            dp = move(next_dp);
        }
        
        return dp[n];
    }
};