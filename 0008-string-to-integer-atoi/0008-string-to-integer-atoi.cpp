class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // Step 1: Skip any leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // If the string is all whitespace, return 0
        if (i == n) return 0;
        
        // Step 2: Determine the sign of the number
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        // Step 3: Read digits and convert to integer with overflow/underflow checks
        long long result = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');
            
            // Step 4: Check and clamp against 32-bit signed integer limits
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        
        // Return the final computed value with its sign applied
        return static_cast<int>(result * sign);
    }
};