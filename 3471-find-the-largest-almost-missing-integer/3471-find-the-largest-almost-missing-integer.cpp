class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int count[51] = {0};

        // Check every subarray of size k
        for (int i = 0; i <= nums.size() - k; i++) {

            // To make sure a number is counted only once
            // inside the current subarray
            bool seen[51] = {false};

            // Visit elements of current subarray
            for (int j = i; j < i + k; j++) {
                seen[nums[j]] = true;
            }

            // Count the numbers present in this subarray
            for (int x = 0; x <= 50; x++) {
                if (seen[x]) {
                    count[x]++;
                }
            }
        }

        // Find the largest number appearing in exactly one subarray
        for (int x = 50; x >= 0; x--) {
            if (count[x] == 1) {
                return x;
            }
        }

        return -1;
    }
};