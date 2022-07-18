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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        if (l == r) return new TreeNode(nums[l]);

        int maxValue = nums[l];
        int mid = l;
        for (int i = l + 1; i <= r; ++i) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                mid = i;
            }
        }

        TreeNode *node = new TreeNode(maxValue);
        node->left = constructMaximumBinaryTree(nums, l, mid - 1);
        node->right = constructMaximumBinaryTree(nums, mid + 1, r);
        return node;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }
};
