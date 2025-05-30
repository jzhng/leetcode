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
    void inorder(TreeNode *node, vector<int> &nums) {
        if (!node) return;
        inorder(node->left, nums);
        nums.push_back(node->val);
        inorder(node->right, nums);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        
        int n = nums.size();
        if (n == 1) return true;
        for (int i = 0; i < n-1; ++i) {
            if (nums[i] >= nums[i+1]) return false;
        }
        return true;
    }
};