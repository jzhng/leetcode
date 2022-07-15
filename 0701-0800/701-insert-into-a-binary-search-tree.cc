struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            TreeNode* node = new TreeNode(val);
            return node;
        }

        TreeNode *prev = nullptr, *curr = root;
        while (curr) {
            prev = curr;
            if (curr->val > val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        TreeNode *node = new TreeNode(val);
        if (prev->val > val) {
            prev->left = node;
        } else {
            prev->right = node;
        }
        return root;
    }
};
