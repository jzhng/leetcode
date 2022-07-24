#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        auto is_subseq = [](string &s, string &t) -> bool {
            int i = 0, j = 0;
            while (i < s.size() && j < t.size()) {
                if (s[i] == t[j]) {
                    ++i;
                }
                ++j;
            }
            return i == s.size();
        };

        int n = strs.size(), res = -1;
        for (int i = 0; i < n; ++i) {
            int len = strs[i].size();
            if (len < res) continue;
            bool check = true;
            for (int j = 0; j < n; ++j) {
                if (i != j && is_subseq(strs[i], strs[j])) {
                    check = false;
                    break;
                }
            }
            if (check) {
                res = len;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"aba", "cdc", "eae"};
    cout << s.findLUSlength(strs) << endl;
    return 0;
}
