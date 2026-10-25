class Solution {
public:
int dfs(vector<vector<int>>& grid, int r, int c) {
int m = grid.size();
int n = grid[0].size();


    if (r < 0 || c < 0 || r >= m || c >= n)
        return 0;

    if (grid[r][c] == 1)
        return 1;

    grid[r][c] = 1;

    int up = dfs(grid, r - 1, c);
    int down = dfs(grid, r + 1, c);
    int left = dfs(grid, r, c - 1);
    int right = dfs(grid, r, c + 1);

    return up && down && left && right;
}

int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                if (dfs(grid, i, j))
                    count++;
            }
        }
    }

    return count;
}


};
