#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Edge cases: if either string is empty or s is shorter than t, a window is impossible.
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Frequency array to store characters required from string t
        int targetCount[128] = {0};
        for (char c : t) {
            targetCount[(unsigned char)c]++;
        }

        // Count how many unique characters need to be present in our window
        int required = 0;
        for (int i = 0; i < 128; ++i) {
            if (targetCount[i] > 0) {
                required++;
            }
        }

        int l = 0, r = 0;
        int formed = 0;
        int windowCounts[128] = {0};
        int minLen = s.length() + 1;
        int minLeft = 0;

        // Expand the window using the right pointer
        while (r < s.length()) {
            unsigned char c = s[r];
            windowCounts[c]++;

            // If the current character's frequency matches its required frequency in t, increment formed
            if (targetCount[c] > 0 && windowCounts[c] == targetCount[c]) {
                formed++;
            }

            // Try and contract the window from the left until it ceases to be 'desirable'
            while (l <= r && formed == required) {
                c = s[l];
                
                // Update minimum window length and starting index
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minLeft = l;
                }

                windowCounts[c]--;
                if (targetCount[c] > 0 && windowCounts[c] < targetCount[c]) {
                    formed--;
                }
                l++;
            }
            r++;
        }

        // If minLen was never updated, return "", otherwise return the substring
        return minLen == s.length() + 1 ? "" : s.substr(minLeft, minLen);
    }
};