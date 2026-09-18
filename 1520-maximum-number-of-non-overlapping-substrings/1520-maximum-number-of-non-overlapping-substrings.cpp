class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        
        int n = s.size();

        // first[c] = first occurrence of character c
        // last[c]  = last occurrence of character c
        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Try to create a valid interval for every character
        for (int c = 0; c < 26; c++) {

            if (last[c] == -1)
                continue;

            int left = first[c];
            int right = last[c];

            bool valid = true;

            for (int i = left; i <= right; i++) {

                int x = s[i] - 'a';

                // This character appeared before our left boundary
                if (first[x] < left) {
                    valid = false;
                    break;
                }

                // We must include all occurrences of this character
                right = max(right, last[x]);
            }

            if (valid) {
                intervals.push_back({left, right});
            }
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<string> ans;

        int prevEnd = -1;

        // Greedily select non-overlapping intervals
        for (auto [left, right] : intervals) {

            if (left > prevEnd) {
                ans.push_back(s.substr(left, right - left + 1));
                prevEnd = right;
            }
        }

        return ans;
    }
};