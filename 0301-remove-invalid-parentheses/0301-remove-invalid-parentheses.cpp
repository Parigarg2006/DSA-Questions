class Solution {
public:

    void removeInvalid(string s, int start,
                       int removeLeft, int removeRight,
                       set<string>& ans) {

        // If no more brackets need to be removed
        if (removeLeft == 0 && removeRight == 0) {

            int balance = 0;

            for (char ch : s) {

                if (ch == '(') {
                    balance++;
                }
                else if (ch == ')') {
                    balance--;
                }

                if (balance < 0) {
                    return;
                }
            }

            if (balance == 0) {
                ans.insert(s);
            }

            return;
        }

        for (int i = start; i < s.size(); i++) {

            // Skip duplicate parentheses
            if (i > start && s[i] == s[i - 1]) {
                continue;
            }

            // Remove '('
            if (removeLeft > 0 && s[i] == '(') {

                string next = s.substr(0, i) +
                              s.substr(i + 1);

                removeInvalid(next, i,
                              removeLeft - 1,
                              removeRight,
                              ans);
            }

            // Remove ')'
            if (removeRight > 0 && s[i] == ')') {

                string next = s.substr(0, i) +
                              s.substr(i + 1);

                removeInvalid(next, i,
                              removeLeft,
                              removeRight - 1,
                              ans);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int balance = 0;
        int removeLeft = 0;
        int removeRight = 0;

        // Find how many '(' and ')' need to be removed
        for (char ch : s) {

            if (ch == '(') {
                balance++;
            }

            else if (ch == ')') {

                if (balance > 0) {
                    balance--;
                }
                else {
                    removeRight++;
                }
            }
        }

        removeLeft = balance;

        set<string> ans;

        removeInvalid(s, 0,
                      removeLeft,
                      removeRight,
                      ans);

        return vector<string>(ans.begin(), ans.end());
    }
};