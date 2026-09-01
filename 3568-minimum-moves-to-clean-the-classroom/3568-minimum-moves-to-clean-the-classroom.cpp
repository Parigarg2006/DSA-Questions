class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int startR = 0;
        int startC = 0;

        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int litterCount = 0;

        // Find S and assign IDs to L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    startR = i;
                    startC = j;
                }

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        // All litter collected
        int allMask = (1 << litterCount) - 1;

        // State = {row, col, energy, mask, moves}
        queue<array<int, 5>> q;

        q.push({startR, startC, energy, 0, 0});

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        visited[startR][startC][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c, e, mask, moves] = q.front();
            q.pop();

            // All litter collected
            if (mask == allMask) {
                return moves;
            }

            // Try 4 directions
            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

                // Obstacle
                if (classroom[nr][nc] == 'X') {
                    continue;
                }

                // Need one energy for the move
                if (e == 0) {
                    continue;
                }

                int newEnergy = e - 1;
                int newMask = mask;

                // Reset energy
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                // Collect litter
                if (classroom[nr][nc] == 'L') {
                    int id = litterId[nr][nc];
                    newMask = mask | (1 << id);
                }

                // Already visited this exact state
                if (visited[nr][nc][newEnergy][newMask]) {
                    continue;
                }

                visited[nr][nc][newEnergy][newMask] = true;

                q.push({
                    nr,
                    nc,
                    newEnergy,
                    newMask,
                    moves + 1
                });
            }
        }

        return -1;
    }
};