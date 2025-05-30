#include <cstdlib>
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
    int closestValue(TreeNode* root, double target) {
        auto node = root;
        int closest = node->val;
        while (node) {
            int val = node -> val;
            closest = abs(val-target) < abs(closest-target) ? val : closest;
            node = target < val ? node->left : node->right;
        }
        return closest;
    }
};