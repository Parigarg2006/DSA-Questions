class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Pointer to track the position where the next non-zero element should be placed
        int lastNonZeroFoundAt = 0;

        // First pass: shift all non-zero elements to the front of the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }

        // Second pass: fill the remaining positions with zeros
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};