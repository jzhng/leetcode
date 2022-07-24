#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = 0, len = s1.size();
        unordered_map<char, char> m;
        for (int i = 0; i < len; ++i) {
            if (s1[i] != s2[i]) {
                ++diff;
                if (m.count(s2[i]) == 1 && m[s2[i]] == s1[i]) {
                    m.erase(s2[i]);
                } else {
                    m[s1[i]] = s2[i];
                }
            }
        }
        return (diff == 0 || (diff == 2 && m.empty()));
    }
};

int main() {
    Solution s;
    cout << s.areAlmostEqual("bank", "kanb") << endl;
    return 0;
}
