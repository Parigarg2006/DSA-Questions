#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        // Step 2: If such an element is found, find the smallest element larger than nums[i] to its right
        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // Swap them
            swap(nums[i], nums[j]);
        }
        
        // Step 3: Reverse the suffix starting from i + 1 to get the next lexicographical permutation
        reverse(nums.begin() + i + 1, nums.end());
    }
};