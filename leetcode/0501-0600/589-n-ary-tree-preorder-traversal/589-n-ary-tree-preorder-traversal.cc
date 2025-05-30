#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
    void preorder_traversal(Node *root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        for (auto &child: root->children) {
            preorder_traversal(child, res);
        }
    }

public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder_traversal(root, res);
        return res;
    }
};
