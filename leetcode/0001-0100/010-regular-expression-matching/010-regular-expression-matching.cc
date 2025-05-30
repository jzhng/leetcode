#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        auto firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (p.length() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        } else {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main() {
    Solution s;
    string s1 = "aa", s2 = "a*";
    cout << s.isMatch(s1, s2) << endl;
    return 0;
}