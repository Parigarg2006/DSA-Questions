class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int maxLeft = nums[0];
            int minRight = nums[i];

            // Find maximum from 0 to i
            for (int j = 0; j <= i; j++) {
                maxLeft = max(maxLeft, nums[j]);
            }

            // Find minimum from i to n-1
            for (int j = i; j < n; j++) {
                minRight = min(minRight, nums[j]);
            }

            // Check if index i is stable
            if (maxLeft - minRight <= k) {
                return i;
            }
        }

        return -1;
    }
};