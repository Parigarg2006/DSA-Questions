#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the overflow edge case where dividend is INT_MIN and divisor is -1
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine the sign of the result using XOR
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        
        // Convert both numbers to long long and take absolute values
        // Using long long prevents overflow when negating or handling INT_MIN
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        long long ans = 0;
        
        // Perform division using bit-shifting (exponential search)
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            // Double the divisor and the multiple as long as it does not exceed the remaining dividend
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            ans += multiple;
        }
        
        return sign * ans;
    }
};