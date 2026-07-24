class Solution {
public:
    string intToRoman(int num) {
        // Arrays containing all possible Roman numeral values and their corresponding symbols,
        // including standard subtractive combinations (e.g., 900 for CM, 400 for CD, etc.).
        const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";
        
        // Iterate through each value from largest to smallest using a greedy approach
        for (int i = 0; i < 13; ++i) {
            // As long as the current value can be subtracted from num, do so
            // and append the corresponding Roman symbol to the result string.
            while (num >= values[i]) {
                num -= values[i];
                result += symbols[i];
            }
        }
        
        return result;
    }
};