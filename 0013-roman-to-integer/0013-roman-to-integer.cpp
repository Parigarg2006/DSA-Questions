#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Map each Roman numeral symbol to its corresponding integer value
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        // Traverse through the Roman numeral string
        for (int i = 0; i < n; i++) {
            // If the current value is less than the next value, it signifies
            // subtractive notation (e.g., IV, IX, XL, etc.)
            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]];
            } else {
                // Otherwise, add the value to the total
                total += roman[s[i]];
            }
        }
        
        return total;
    }
};