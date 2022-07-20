struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    int pre = 0;
    void traversal(TreeNode *node) {
        if (!node) return;
        traversal(node->right);
        node->val += pre;
        pre = node->val;
        traversal(node->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
};
