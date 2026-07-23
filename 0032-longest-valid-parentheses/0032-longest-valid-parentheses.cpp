#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // Stack to store the indices of parentheses
        stack<int> st;
        
        // Push -1 as a base index for finding length of valid substrings
        st.push(-1);
        
        int max_len = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                // Push the index of the opening parenthesis
                st.push(i);
            } else {
                // Pop the top element for the current ')'
                st.pop();
                
                if (st.empty()) {
                    // If the stack is empty, use the current index as the new base
                    st.push(i);
                } else {
                    // Calculate the length of the valid parenthesis substring
                    max_len = max(max_len, i - st.top());
                }
            }
        }
        
        return max_len;
    }
};