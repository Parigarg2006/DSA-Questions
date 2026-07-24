class Solution {
public:
    string longestPalindrome(string s) {
        // Handle edge case for empty string
        if (s.empty()) return "";
        
        int start = 0;
        int maxLength = 0;
        int n = s.length();
        
        // Every character and space between characters can be a center for a palindrome
        for (int i = 0; i < n; ++i) {
            // Case 1: Odd length palindrome (centered at i)
            int len1 = expandAroundCenter(s, i, i);
            // Case 2: Even length palindrome (centered between i and i + 1)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            
            // Update the longest palindrome found so far
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLength);
    }

private:
    // Helper function to expand around the given left and right centers
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the valid palindrome
        return right - left - 1;
    }
};