#include <vector>
#include <unordered_set>
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
    void inorder(TreeNode* node, vector<int> &nums) {
        if (!node) return;
        inorder(node->left, nums);
        nums.push_back(node->val);
        inorder(node->right, nums);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);

        unordered_set<int> st;
        for (int n: nums) {
            if (st.count(k - n)) {
                return true;
            }
            st.insert(n);
        }
        return false;
    }
};