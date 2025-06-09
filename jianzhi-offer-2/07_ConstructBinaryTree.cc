// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。

// https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/description/
// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> idx;
        for (int i = 0; i < n; ++i) {
            idx[inorder[i]] = i;
        }

        auto dfs = [&](this auto &&dfs, int pre_l, int pre_r, int in_l, int in_r) -> TreeNode* {
            if (pre_l == pre_r) return nullptr;
            int left_size = idx[preorder[pre_l]] - in_l;

            TreeNode* left = dfs(pre_l + 1, pre_l + 1 + left_size, in_l, in_l + left_size);
            TreeNode* right = dfs(pre_l + 1 + left_size, pre_r, in_l + left_size + 1, in_r);
            return new TreeNode(preorder[pre_l], left, right);
        };
        return dfs(0, n, 0, n);
    }
};

class Solution {
public:
    TreeNode* deduceTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
    
        unordered_map<int, int> inorder_idx;
        for (int i = 0; i < n; ++i) {
            inorder_idx[inorder[i]] = i;
        }

        auto recur = [&](this auto &&recur, int pre_root, int in_left, int in_right) -> TreeNode* {
            if (in_left > in_right) {
                return nullptr;
            }

            int mid = inorder_idx[preorder[pre_root]];

            auto left = recur(pre_root + 1, in_left, mid - 1);
            auto right = recur(pre_root + mid - in_left + 1, mid + 1, in_right);
            return new TreeNode(preorder[pre_root], left, right);
        };

        return recur(0, 0, n - 1);
    }
};
