#include <iostream>
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
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        if (root->left == root->right) return true;

        TreeNode *left = root->left, *right = root->right;
        queue<TreeNode *> q;
        q.push(left);
        q.push(right);
        int loop = 0;
        while (!q.empty()) {
            left = q.front();
            q.pop();
            right = q.front();
            q.pop();
            if ((left == nullptr && right != nullptr) ||
                (right == nullptr && left != nullptr)) {
                return false;
            }
            if (left != nullptr && right != nullptr) {
                if (left->val != right->val) {
                    return false;
                }
                q.push(left->left);
                q.push(right->right);
                q.push(left->right);
                q.push(right->left);
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(2, new TreeNode(3), nullptr));
    cout << s.isSymmetric(root) << endl;
    TreeNode *root2 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(2, nullptr, new TreeNode(3)));
    cout << s.isSymmetric(root2) << endl;

    return 0;
}
