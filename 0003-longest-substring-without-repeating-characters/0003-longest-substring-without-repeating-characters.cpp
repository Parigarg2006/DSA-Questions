#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Array to store the last seen index of each ASCII character (size 256 for all extended ASCII)
        vector<int> lastIndex(256, -1);
        int maxLen = 0;
        int left = 0;

        // Expand the right boundary of the sliding window
        for (int right = 0; right < (int)s.length(); ++right) {
            unsigned char c = s[right];

            // If the character has been seen within the current window, shrink the window from the left
            if (lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }

            // Update the last seen index of the current character
            lastIndex[c] = right;

            // Calculate the maximum length encountered so far
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};