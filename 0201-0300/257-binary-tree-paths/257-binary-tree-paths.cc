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
    void dfs(TreeNode* node, vector<int> &path, vector<string> &res) {
        path.push_back(node->val);

        if (!node->left && !node->right) {
            string s = "";
            for (int i = 0; i < path.size() - 1; ++i) {
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path.back());
            res.push_back(s);
            return;
        }

        if (node->left) {
            dfs(node->left, path, res);
            path.pop_back();
        }

        if (node->right) {
            dfs(node->right, path, res);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (root) dfs(root, path, res);
        return res;
    }
};