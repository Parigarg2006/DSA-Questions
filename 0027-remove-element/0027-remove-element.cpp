#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Pointer 'k' keeps track of the count of elements not equal to 'val'
        // and the next insertion position in the array.
        int k = 0;
        
        // Iterate through each element in the array.
        for (int i = 0; i < nums.size(); ++i) {
            // If the current element is not equal to val, we keep it.
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        
        // Return the number of elements remaining after removal.
        return k;
    }
};