class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";
        int depth = 0;

        for (char ch : s) {

            if (ch == '(') {

                // If depth is already > 0,
                // this is NOT the outermost '('
                if (depth > 0) {
                    ans += ch;
                }

                depth++;
            }

            else {

                depth--;

                // If depth is still > 0,
                // this is NOT the outermost ')'
                if (depth > 0) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};