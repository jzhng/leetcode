#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            if (node) {
                if (node->right) stk.push(node->right);
                stk.push(node);
                stk.push(nullptr);
                if (node->left) stk.push(node->left);
            } else {
                node = stk.top();
                stk.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};
