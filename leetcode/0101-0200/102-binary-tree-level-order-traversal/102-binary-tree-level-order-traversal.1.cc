#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void levelOrder(TreeNode* node, int depth, vector<vector<int>> &res) {
        if (!node) return;
        if (res.size() <= depth) res.push_back(vector<int>());
        res[depth].push_back(node->val);
        levelOrder(node->left, depth+1, res);
        levelOrder(node->right, depth+1, res);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root, 0, res);
        return res;
    }
};
