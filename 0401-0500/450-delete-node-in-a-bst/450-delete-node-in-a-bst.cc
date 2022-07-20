struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    TreeNode* deleteNode(TreeNode *node) {
        if (!node) return nullptr;
        if (!node->right) return node->left;

        auto curr = node->right;
        while (curr->left) curr = curr->left;
        curr->left = node->left;

        return node->right;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *pre = nullptr, *curr = root;
        while (curr) {
            if (curr->val == key) break;
            pre = curr;
            if (key < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if (!pre) return deleteNode(curr);
        if (pre->left == curr) {
            pre->left = deleteNode(curr);
        } else {
            pre->right = deleteNode(curr);
        }
    
        return root;
    }
};
