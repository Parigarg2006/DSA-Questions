#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.size();
        
        // Step 1: Check if already sorted
        bool sorted = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            return 0;
        }
        
        // Step 2: If length is 2 and not sorted, it's impossible
        if (n == 2) {
            return -1;
        }
        
        char mn = *std::min_element(s.begin(), s.end());
        char mx = *std::max_element(s.begin(), s.end());
        
        // Step 3: Check if 1 operation is enough
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        
        // Step 4: Check if 2 operations are enough
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
        
        // Step 5: Otherwise, 3 operations are required
        return 3;
    }
};