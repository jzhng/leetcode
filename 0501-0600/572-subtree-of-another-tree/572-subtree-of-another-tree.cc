struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    bool isSametree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return (p == q);
        return isSametree(p->left, q->left) &&
               isSametree(p->right, q->right) &&
               (p->val == q->val);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot) return (root == subRoot);
        return isSametree(root, subRoot) ||
               isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};