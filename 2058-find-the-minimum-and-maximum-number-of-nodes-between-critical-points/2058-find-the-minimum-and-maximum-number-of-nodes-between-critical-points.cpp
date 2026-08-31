class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans = {-1, -1};

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return ans;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int pos = 2;

        int first = -1;
        int last = -1;
        int minDistance = INT_MAX;

        while (next != nullptr) {

            // Check if curr is a critical point
            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (isCritical) {

                if (first == -1) {
                    // First critical point
                    first = pos;
                } 
                else {
                    // Distance from previous critical point
                    minDistance = min(minDistance, pos - last);
                }

                // Current becomes the latest critical point
                last = pos;
            }

            // Move forward
            prev = curr;
            curr = next;
            next = next->next;

            pos++;
        }

        // Fewer than two critical points
        if (first == -1 || first == last) {
            return {-1, -1};
        }

        int maxDistance = last - first;

        return {minDistance, maxDistance};
    }
};