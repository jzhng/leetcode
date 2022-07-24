
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  unordered_map<int, int> cnt;
  int max_cnt = 0;

  int dfs(TreeNode *node) {
    if (!node) {
      return 0;
    }
    int sum = node->val + dfs(node->left) + dfs(node->right);
    max_cnt = max(max_cnt, ++cnt[sum]);
    return sum;
  }

 public:
  vector<int> findFrequentTreeSum(TreeNode *root) {
    dfs(root);
    vector<int> res;
    for (auto &[k, v] : cnt) {
      if (v == max_cnt) {
        res.push_back(k);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(2);
  root->right = new TreeNode(-3);
  vector<int> res = s.findFrequentTreeSum(root);
  for (auto i : res) {
    std::cout << i << " ";
  }
  cout << endl;
}