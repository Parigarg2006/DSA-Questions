#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        // If there are fewer than 4 elements, a quadruplet cannot be formed.
        if (n < 4) return result;
        
        // Sort the array to facilitate duplicate skipping and two-pointer traversal.
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicate elements for the first number to ensure unique quadruplets.
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicate elements for the second number.
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                // Use long long to prevent integer overflow during calculations.
                long long target2 = (long long)target - nums[i] - nums[j];
                int left = j + 1, right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[left] + nums[right];
                    
                    if (sum == target2) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for the third and fourth numbers.
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (sum < target2) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};