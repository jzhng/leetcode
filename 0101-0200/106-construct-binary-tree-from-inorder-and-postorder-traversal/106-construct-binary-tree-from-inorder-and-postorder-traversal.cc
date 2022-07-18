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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
            int lin, int rin, int lpost, int rpost) {
        if (lin > rin) return nullptr;
        int rootin = index[postorder[rpost]];
        TreeNode *node = new TreeNode(inorder[rootin]);
        node->left = buildTree(inorder, postorder, lin, rootin-1, lpost, lpost+rootin-lin-1);
        node->right = buildTree(inorder, postorder, rootin+1, rin, lpost+rootin-lin, rpost-1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return buildTree(inorder, postorder, 0, n-1, 0, n-1);
    }
};

int main() {
    Solution s;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode *root = s.buildTree(inorder, postorder);
    return 0;
}