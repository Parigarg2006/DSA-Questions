class Solution {
public:
    string reverseParentheses(string s) {

        stack<string> st;
        st.push("");

        for (char ch : s) {

            if (ch == '(') {
                // New bracket starts
                st.push("");
            }

            else if (ch == ')') {
                // Current bracket string
                string temp = st.top();
                st.pop();

                // Reverse it
                reverse(temp.begin(), temp.end());

                // Add it to previous string
                st.top() += temp;
            }

            else {
                // Normal character
                st.top() += ch;
            }
        }

        return st.top();
    }
};