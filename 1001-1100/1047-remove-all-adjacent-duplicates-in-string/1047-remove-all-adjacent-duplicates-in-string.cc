#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (auto &c: s) {
            if (!res.empty() && res.back() == c) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
