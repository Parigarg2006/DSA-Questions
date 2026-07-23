class Solution {
private:
    // Helper recursive function using bit manipulation to track queen placements
    void solve(int row, int n, int cols, int d1, int d2, int& count) {
        // Base case: If all queens are placed successfully, increment the count
        if (row == n) {
            count++;
            return;
        }
        
        // Find all available positions for the current row
        // (cols | d1 | d2) gives all attacked positions in the current row
        int available = ((1 << n) - 1) & (~(cols | d1 | d2));
        
        // Iterate through each available position using bit manipulation
        while (available > 0) {
            int p = available & -available; // Extract the lowest set bit
            available -= p; // Clear the extracted bit
            
            // Recurse to the next row, updating the column and diagonal masks
            solve(row + 1, n, cols | p, (d1 | p) << 1, (d2 | p) >> 1, count);
        }
    }

public:
    // Main function to return the total number of distinct N-Queens solutions
    int totalNQueens(int n) {
        int count = 0;
        solve(0, n, 0, 0, 0, count);
        return count;
    }
};