#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    bool check(unordered_map<char, int> &ss) {
        for (auto &i : ss) {
            if (i.second > 0) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();

        unordered_map<char, int> hm;
        for (char c: t) {
            ++hm[c];
        }

        int len = m + 1, idx = 0;
        for (int l = 0, r = 0; r < m; ++r) {
            if (hm[s[r]] > 0) {
                --n;
            }
            --hm[s[r]];
            while (n == 0) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    idx = l;
                }
                if (hm[s[l]] == 0) {
                    ++n;
                }
                ++hm[s[l]];
                ++l;
            }
        }

        return len == m + 1 ?  "" : s.substr(idx, len);
    }
};

int main() {
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}