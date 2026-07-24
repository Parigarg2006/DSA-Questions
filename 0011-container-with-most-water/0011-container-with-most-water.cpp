#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // Initialize two pointers: left at the beginning and right at the end
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;
        
        // Loop until the two pointers meet
        while (left < right) {
            // The height of the container is limited by the shorter line
            int current_height = min(height[left], height[right]);
            // The width of the container is the distance between the two pointers
            int current_width = right - left;
            // Calculate the area
            int current_area = current_height * current_width;
            
            // Update the maximum water found so far
            max_water = max(max_water, current_area);
            
            // Move the pointer of the shorter line inward to try and find a taller line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};