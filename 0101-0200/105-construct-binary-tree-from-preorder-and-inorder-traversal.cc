#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> index;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
        int lpre, int rpre, int lin, int rin) {
        if (lpre > rpre) return nullptr;

        TreeNode *node = new TreeNode(preorder[lpre]);
        int rootin = index[preorder[lpre]];
        node->left = buildTree(preorder, inorder, lpre + 1, lpre + rootin - lin, lin, rootin - 1);
        node->right = buildTree(preorder, inorder, lpre + rootin - lin + 1, rpre, rootin + 1, rin);
        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, n-1, 0, n-1);
    }
};

int main() {
    Solution s;
    vector<int> preorder = {1,2};
    vector<int> inorder = {2,1};
    TreeNode *root = s.buildTree(preorder, inorder);
    return 0;
}