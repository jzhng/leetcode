#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    void inorder(TreeNode* node, vector<int>& visited) {
        if (!node) return;
        inorder(node->left, visited);
        visited.push_back(node->val);
        inorder(node->right, visited);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> visited;
        inorder(root, visited);
        return visited;
    }
};
