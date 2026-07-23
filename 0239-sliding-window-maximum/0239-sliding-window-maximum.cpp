#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        // Store indices of elements in the array to easily check window bounds
        deque<int> dq;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices that are out of the current sliding window [i - k + 1, i]
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // Maintain a monotonic decreasing queue by popping elements 
            // smaller than or equal to the current element
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            // Push current element index onto the back of the deque
            dq.push_back(i);
            
            // Once the first window of size k is reached, record the maximum
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};