#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void dfs(TreeNode* node, int depth, vector<int> &leftmost) {
        if (leftmost.size() < depth) leftmost.push_back(node->val);
        if (node->left) dfs(node->left, depth+1, leftmost);
        if (node->right) dfs(node->right, depth+1, leftmost);
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        vector<int> leftmost;
        dfs(root, 1, leftmost);
        return leftmost.back();
    }
};
