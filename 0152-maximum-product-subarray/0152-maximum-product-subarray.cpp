#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    /**
     * Calculates the maximum product of a contiguous subarray.
     * Uses dynamic programming to track both the maximum and minimum products
     * ending at the current position, as a negative number can flip the 
     * minimum product into a new maximum.
     */
    long long maxProduct(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        // Initialize tracking variables with the first element
        long long max_so_far = nums[0];
        long long min_so_far = nums[0];
        long long result = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            long long curr = nums[i];

            // Store current max_so_far before updating it, as it is needed
            // to calculate the new min_so_far.
            long long temp_max = max_so_far;

            // The new max/min is either the current element itself, 
            // or the current element multiplied by the previous max/min.
            max_so_far = std::max({curr, max_so_far * curr, min_so_far * curr});
            min_so_far = std::min({curr, temp_max * curr, min_so_far * curr});

            // Update the global result
            result = std::max(result, max_so_far);
        }

        return result;
    }
};