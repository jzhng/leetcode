#include <unordered_map>
#include <vector>
#include <string>
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
    string dfs(TreeNode* node, unordered_map<string, int> &mp, vector<TreeNode*> &res) {
        if (!node) return "";
        string key = to_string(node->val);
        key += "," + dfs(node->left, mp, res);
        key += "," + dfs(node->right, mp, res);

        if (++mp[key] == 2) {
            res.emplace_back(node);
        }
        return key;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> res;
        dfs(root, mp, res);
        return res;
    }
};
