class Solution {
public:
    bool checkValidString(string s) {

        int minOpen = 0;
        int maxOpen = 0;

        for (char ch : s) {

            if (ch == '(') {
                minOpen++;
                maxOpen++;
            }

            else if (ch == ')') {
                minOpen--;
                maxOpen--;
            }

            else {  // '*'
                minOpen--;
                maxOpen++;
            }

            // Minimum opens cannot be negative
            minOpen = max(0, minOpen);

            // Even maximum possible opens became negative
            // means too many ')' came
            if (maxOpen < 0) {
                return false;
            }
        }

        return minOpen == 0;
    }
};