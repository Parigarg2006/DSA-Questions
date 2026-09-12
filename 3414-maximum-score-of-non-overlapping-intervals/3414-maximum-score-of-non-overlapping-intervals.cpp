class Solution {
public:

    struct State {
        long long score;
        vector<int> indices;
    };

    State better(State a, State b) {
        if (a.score != b.score)
            return (a.score > b.score) ? a : b;

        return (a.indices < b.indices) ? a : b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Store {left, right, weight, original_index}
        vector<array<long long, 4>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by left endpoint
        sort(arr.begin(), arr.end());

        vector<long long> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = arr[i][0];
        }

        // dp[i][k] = best answer from i onward using at most k intervals
        vector<vector<State>> dp(
            n + 1,
            vector<State>(5, {0, {}})
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: skip current interval
                State skip = dp[i + 1][k];

                // Find first interval whose left > current right
                int next = upper_bound(
                    starts.begin(),
                    starts.end(),
                    arr[i][1]
                ) - starts.begin();

                // Option 2: take current interval
                State take = dp[next][k - 1];

                take.score += arr[i][2];
                take.indices.push_back((int)arr[i][3]);

                sort(take.indices.begin(), take.indices.end());

                dp[i][k] = better(skip, take);
            }
        }

        return dp[0][4].indices;
    }
};