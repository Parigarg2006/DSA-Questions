class Solution {
public:
    /**
     * Calculates the minimum edit distance between two strings using dynamic programming.
     * Uses space optimization to reduce space complexity from O(N*M) to O(min(N, M)).
     */
    int minDistance(std::string word1, std::string word2) {
        int n = static_cast<int>(word1.length());
        int m = static_cast<int>(word2.length());

        // Ensure word2 is the shorter string to minimize space usage
        if (n < m) {
            return minDistance(word2, word1);
        }

        // prev stores the results of the previous row, curr stores the current row
        std::vector<int> prev(m + 1);
        std::vector<int> curr(m + 1);

        // Base case: transforming an empty string to a string of length j requires j insertions
        for (int j = 0; j <= m; ++j) {
            prev[j] = j;
        }

        for (int i = 1; i <= n; ++i) {
            // Base case: transforming a string of length i to an empty string requires i deletions
            curr[0] = i;
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Characters match, no new operation needed
                    curr[j] = prev[j - 1];
                } else {
                    // Take the minimum of insert, delete, or replace operations
                    curr[j] = 1 + std::min({prev[j], curr[j - 1], prev[j - 1]});
                }
            }
            // Move current row to previous for the next iteration
            prev = curr;
        }

        return prev[m];
    }
};