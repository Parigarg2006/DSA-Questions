#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        // If there are 2 or fewer points, they all trivially lie on the same line
        if (n <= 2) return n;

        int max_points = 0;

        // Iterate through each point and treat it as the anchor point
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slope_counts;
            int duplicates = 1; // Count the anchor point itself
            int local_max = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // Handle duplicate points (same coordinates)
                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                // Reduce the slope fraction using the greatest common divisor (GCD)
                int g = std::gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Normalize the sign to ensure identical slopes share the same representation
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                string slope = to_string(dx) + "_" + to_string(dy);
                slope_counts[slope]++;
                local_max = max(local_max, slope_counts[slope]);
            }

            // Total points on the line passing through the anchor point 'i'
            max_points = max(max_points, local_max + duplicates);
        }

        return max_points;
    }
};