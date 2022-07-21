/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */

// @lc code=start
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
class BSTIterator {
    vector<int> values;
    int index = 0;
public:
    BSTIterator(TreeNode* root) {
        if (root) {
            stack<TreeNode*> st;
            auto cur = root;
            while (cur ||!st.empty()) {
                if (cur) {
                    st.push(cur);
                    cur = cur->left;
                } else {
                    cur = st.top();
                    st.pop();
                    values.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
    }
    
    int next() {
        return values[index++];
    }
    
    bool hasNext() {
        return index < values.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

