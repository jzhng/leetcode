#include <string>
using namespace std;

class Solution {
    string normalize(string &s) {
        string ss;
        for (auto c: s) {
            if (c == '#') {
                if (!ss.empty()) ss.pop_back();
            } else {
                ss.push_back(c);
            }
        }
        return ss;
    }

public:
    bool backspaceCompare(string s, string t) {
        return normalize(s) == normalize(t);
    }
};