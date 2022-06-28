#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> m;
        for (char c: s) {
            ++m[c];
        }

        for (auto c: t) {
            if (--m[c] == 0) {
                m.erase(c);
            }
        }

        return m.empty();
    }
};
