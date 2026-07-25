#include <algorithm>
using namespace std;


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, the trees are structurally identical up to this point
        if (!p && !q) {
            return true;
        }
        // If one of the nodes is null and the other is not, the trees are different
        if (!p || !q) {
            return false;
        }
        // If the values of the current nodes differ, the trees are different
        if (p->val != q->val) {
            return false;
        }
        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};