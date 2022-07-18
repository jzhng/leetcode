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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode *> stk;
        TreeNode *curr = root, *pre = nullptr;
        int cnt, maxCnt;
        while (curr || !stk.empty()) {
            if (curr) {
                stk.push(curr);
                curr = curr->left;
            } else {
                curr = stk.top();
                stk.pop();
                if (!pre) {
                    cnt = 1;
                } else if (pre->val == curr->val) {
                    ++cnt;
                } else {
                    cnt = 1;
                }
                
                if (maxCnt == cnt) {
                    res.push_back(curr->val);
                } else if (maxCnt < cnt) {
                    maxCnt = cnt;
                    res.clear();
                    res.push_back(curr->val);
                }

                pre = curr;
                curr = curr->right;
            }
        }
        return res;
    }
};