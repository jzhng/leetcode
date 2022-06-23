#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    unordered_map<Node*, Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node *clone = new Node(node->val);
        m[node] = clone;
        for (auto &n: node->neighbors) {
            auto it = m.find(n);
            if (it != m.end()) {
                clone->neighbors.push_back(it->second);
            } else {
                clone->neighbors.push_back(cloneGraph(n));
            }
        }
        return clone;
        
    }
};