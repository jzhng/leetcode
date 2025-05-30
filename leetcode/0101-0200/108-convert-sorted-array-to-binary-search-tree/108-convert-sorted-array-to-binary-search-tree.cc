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
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nullptr;
        }

        int m = (l + r) / 2;
        return new TreeNode(
            nums[m],
            sortedArrayToBST(nums, l, m),
            sortedArrayToBST(nums, m+1, r)
        );
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};
