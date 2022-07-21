#include <iostream>
#include <vector>
#include <string>
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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res = "";
        if (root) {
            res += to_string(root->val) + ",";
            if (root->children.size() > 0) {
                res += "[";
            }
            for (auto &child: root->children) {
                res += serialize(child);
            }
            if (root->children.size() > 0) {
                res += "]";
            }
        }
        return res;
    }
	
    vector<Node *> rdeserialize(string data, int &pos) {
        int i = pos;
        vector<Node *> res;
        while (i < data.size()) {
            if (data[i] == ',') {
                Node *node = new Node(stoi(data.substr(pos, i-pos)));
                res.push_back(node);
                pos = i + 1;
            } else if (data[i] == '[') {
                ++i;
                vector<Node *> children = rdeserialize(data, i);
                pos = i + 1;
                res.back()->children = children;
            } else if (data[i] == ']') {
                return res;
            }
            ++i;
        }
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data == "") return nullptr;
        int pos = 0;
        vector<Node *> res = rdeserialize(data, pos);
        return res[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    Codec codec;
    Node *root = new Node(1);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(4));
    root->children.push_back(new Node(5));
    root->children[1]->children.push_back(new Node(6));
    root->children[1]->children.push_back(new Node(7));
    root->children[2]->children.push_back(new Node(8));
    root->children[3]->children.push_back(new Node(9));
    root->children[3]->children.push_back(new Node(10));
    root->children[1]->children[1]->children.push_back(new Node(11));
    root->children[2]->children[0]->children.push_back(new Node(12));
    root->children[3]->children[0]->children.push_back(new Node(13));
    root->children[1]->children[1]->children[0]->children.push_back(new Node(14));

    string data = codec.serialize(root);
    cout << data << endl;
    Node *root2 = codec.deserialize(data);
    cout << root2->val << endl;
    return 0;
}
