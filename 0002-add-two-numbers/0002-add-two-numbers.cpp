class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            int x = 0;
            int y = 0;

            if (l1 != nullptr) {
                x = l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                y = l2->val;
                l2 = l2->next;
            }

            int sum = x + y + carry;

            carry = sum / 10;

            int digit = sum % 10;

            current->next = new ListNode(digit);

            current = current->next;
        }

        return dummy->next;
    }
};