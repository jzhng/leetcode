#include <stack>
#include <climits>
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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode *> st;
        int res = INT_MAX;

        TreeNode *cur = root, *pre = nullptr;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                if (pre) {
                    res = min(res, cur->val - pre->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return res;
    }
};