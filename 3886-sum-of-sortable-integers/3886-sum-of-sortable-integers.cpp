class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevMax = -1;

            for (int start = 0; start < n; start += k) {
                int descents = 0;
                int breakIndex = -1;

                for (int j = 0; j < k; j++) {
                    int curr = nums[start + j];
                    int next = nums[start + (j + 1) % k];

                    if (curr > next) {
                        descents++;
                        breakIndex = j;
                    }
                }

                if (descents > 1) {
                    valid = false;
                    break;
                }

                int mn, mx;

                if (descents == 1) {
                    mn = nums[start + (breakIndex + 1) % k];
                    mx = nums[start + breakIndex];
                } else {
                    mn = nums[start];
                    mx = nums[start];
                }

                if (prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};