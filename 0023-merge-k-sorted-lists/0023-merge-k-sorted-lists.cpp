#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Define a custom comparator for the min-heap to order nodes by ascending value
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        // Min-priority queue to store the current head of each of the k lists
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        // Initialize the heap with the head node of each non-empty list
        for (auto l : lists) {
            if (l != nullptr) {
                minHeap.push(l);
            }
        }

        // Dummy node to serve as the start of the merged linked list
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Extract the smallest node, append it to the result, and push its next node into the heap
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
    }
};