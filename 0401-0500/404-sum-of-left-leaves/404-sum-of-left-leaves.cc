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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;

        int left, right = 0;
        if (root->left && !root->left->left && !root->left->right) {
            left = root->left->val;
        } else {
            left = sumOfLeftLeaves(root->left);
        }

        right = sumOfLeftLeaves(root->right);

        return left + right;
    }
};