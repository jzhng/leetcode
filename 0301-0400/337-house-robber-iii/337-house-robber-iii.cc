class Solution {
    vector<int> robTree(TreeNode* node) {
        if (!node) return {0, 0};

        vector<int> left = robTree(node->left);
        vector<int> right = robTree(node->right);

        int val1 = max(left[0], left[1]) + max(right[0], right[1]);       
        int val2 = node->val + left[0] + right[0];
        return {val1, val2};
    }

public:
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
};
