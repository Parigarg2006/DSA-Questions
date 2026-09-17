class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        const int INF = 1e9;

        // best[i] = minimum length of a valid subarray
        // completely inside arr[0...i]
        vector<int> best(n, INF);

        int left = 0;
        long long sum = 0;

        int ans = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Reduce window if sum becomes greater than target
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // If current window has sum = target
            if (sum == target) {

                int currentLength = right - left + 1;

                // Need a previous subarray ending before 'left'
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans,
                              best[left - 1] + currentLength);
                }
            }

            // Carry forward the best answer seen so far
            if (right == 0) {
                best[right] = INF;
            } else {
                best[right] = best[right - 1];
            }

            // Current subarray itself can be the best
            if (sum == target) {
                int currentLength = right - left + 1;
                best[right] = min(best[right], currentLength);
            }
        }

        if (ans == INF)
            return -1;

        return ans;
    }
};