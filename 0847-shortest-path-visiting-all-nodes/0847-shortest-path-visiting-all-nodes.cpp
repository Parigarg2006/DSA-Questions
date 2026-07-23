class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        // Queue stores pairs of (current_node, visited_nodes_bitmask)
        queue<pair<int, int>> q;
        // visited[node][mask] keeps track of whether we have visited this state
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        // Initialize BFS by starting at every node simultaneously
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }

        int targetMask = (1 << n) - 1;
        int steps = 0;

        // Perform BFS layer by layer
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [curr, mask] = q.front();
                q.pop();

                // If all nodes have been visited, return the current step count
                if (mask == targetMask) {
                    return steps;
                }

                // Explore all neighbors
                for (int neighbor : graph[curr]) {
                    int nextMask = mask | (1 << neighbor);
                    if (!visited[neighbor][nextMask]) {
                        visited[neighbor][nextMask] = true;
                        q.push({neighbor, nextMask});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};