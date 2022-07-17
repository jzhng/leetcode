#include <queue>
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
public:
    int minDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode *> q;
        if (root) q.push(root);

        while (!q.empty()) {
            int n = q.size();
            ++depth;
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (!node->left && !node->right) return depth;
            }
        }
        return depth;
    }
};