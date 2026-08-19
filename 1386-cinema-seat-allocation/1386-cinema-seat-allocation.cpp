class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // Store reserved seats for each row
        unordered_map<int, int> mp;

        // Create bitmask for every reserved seat
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row] |= (1 << col);
        }

        // Every completely empty row can accommodate 2 groups
        long long ans = 2LL * n;

        // Masks for the three possible blocks
        int left   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        // Process only rows having reserved seats
        for (auto &[row, mask] : mp) {

            // We had initially counted 2 groups for this row
            ans -= 2;

            bool leftFree = (mask & left) == 0;
            bool middleFree = (mask & middle) == 0;
            bool rightFree = (mask & right) == 0;

            if (leftFree && rightFree) {
                // Can place two groups
                ans += 2;
            }
            else if (leftFree || middleFree || rightFree) {
                // Can place one group
                ans += 1;
            }
        }

        return (int)ans;
    }
};