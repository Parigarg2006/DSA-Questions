#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * Calculates the total amount of trapped rainwater using a two-pointer approach.
     * 
     * The algorithm maintains two pointers (left and right) and two variables (leftMax and rightMax)
     * to track the maximum height encountered from both ends. Water trapped at any index is 
     * determined by the smaller of the two maximums minus the current height.
     */
    int trap(std::vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        long long water = 0;

        while (left < right) {
            // Always process the side with the smaller height to ensure we are
            // bounded by the correct maximum.
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += (long long)(leftMax - height[left]);
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += (long long)(rightMax - height[right]);
                }
                right--;
            }
        }

        return static_cast<int>(water);
    }
};