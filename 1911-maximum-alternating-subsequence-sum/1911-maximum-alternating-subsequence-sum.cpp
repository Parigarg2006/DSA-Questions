#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Calculates the maximum alternating sum of any subsequence.
     * 
     * We use dynamic programming to maintain two states:
     * - even: The maximum alternating sum of a subsequence ending at an even index.
     * - odd: The maximum alternating sum of a subsequence ending at an odd index.
     * 
     * For each element x in nums:
     * - To update 'even', we can either keep the previous 'even' or add x to an 'odd' subsequence.
     * - To update 'odd', we can either keep the previous 'odd' or subtract x from an 'even' subsequence.
     */
    long long maxAlternatingSum(vector<int>& nums) {
        long long even = 0;
        long long odd = 0;

        for (int x : nums) {
            // Calculate next states based on current values
            long long next_even = max(even, odd + x);
            long long next_odd = max(odd, even - x);
            
            even = next_even;
            odd = next_odd;
        }

        return even;
    }
};