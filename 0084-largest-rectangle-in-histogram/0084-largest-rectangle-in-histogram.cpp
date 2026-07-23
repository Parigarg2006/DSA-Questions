#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int max_area = 0;
        
        // Iterate through all bars including a virtual bar of height 0 at the end
        for (int i = 0; i <= n; i++) {
            // Pop elements from the stack while the current bar is shorter
            // than the bar at the stack's top (or we reached the end boundary)
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                
                // Calculate the width of the rectangle with the popped height
                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        
        return max_area;
    }
};