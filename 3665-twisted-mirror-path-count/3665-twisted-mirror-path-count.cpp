class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        vector<vector<int>> right(m, vector<int>(n, 0));
        vector<vector<int>> down(m, vector<int>(n, 0));

        // Initially, robot starts at (0,0)
        right[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int fromLeft = right[i][j];
                int fromTop = down[i][j];

                // Destination reached
                if (i == m - 1 && j == n - 1) {
                    return (fromLeft + fromTop) % MOD;
                }

                if (grid[i][j] == 0) {

                    // Empty cell: robot can move right or down
                    int ways = (fromLeft + fromTop) % MOD;

                    if (j + 1 < n) {
                        right[i][j + 1] =
                            (right[i][j + 1] + ways) % MOD;
                    }

                    if (i + 1 < m) {
                        down[i + 1][j] =
                            (down[i + 1][j] + ways) % MOD;
                    }

                } 
                else {

                    // Mirror cell:
                    // Entering from left -> redirected down
                    if (i + 1 < m) {
                        down[i + 1][j] =
                            (down[i + 1][j] + fromLeft) % MOD;
                    }

                    // Entering from top -> redirected right
                    if (j + 1 < n) {
                        right[i][j + 1] =
                            (right[i][j + 1] + fromTop) % MOD;
                    }
                }
            }
        }

        return 0;
    }
};