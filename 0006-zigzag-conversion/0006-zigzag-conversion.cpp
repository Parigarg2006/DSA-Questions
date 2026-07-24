#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // Base case: if numRows is 1 or greater than/equal to string length, no zigzag needed.
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Vector to store characters for each row.
        vector<string> rows(min(numRows, (int)s.length()));
        int curRow = 0;
        bool goingDown = false;

        // Iterate through each character in the string and place it in the correct row.
        for (char c : s) {
            rows[curRow].push_back(c);
            // Change direction when we hit the top or bottom row.
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            // Move up or down.
            curRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows to form the final converted string.
        string result = "";
        for (const string& row : rows) {
            result += row;
        }
        return result;
    }
};