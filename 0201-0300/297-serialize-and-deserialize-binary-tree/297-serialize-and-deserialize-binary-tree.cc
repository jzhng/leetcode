#include <string>
#include <list>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Codec {
    void rserialize(TreeNode* root, string& s) {
        if (root == nullptr) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        rserialize(root->left, s);
        rserialize(root->right, s);
    }

    TreeNode* rdeserialize(list<string> &values) {
        if (values.front() == "#") {
            values.erase(values.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(values.front()));
        values.erase(values.begin());
        root->left = rdeserialize(values);
        root->right = rdeserialize(values);
        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        rserialize(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> values;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                values.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            values.push_back(str);
            str.clear();
        }

        return rdeserialize(values);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
