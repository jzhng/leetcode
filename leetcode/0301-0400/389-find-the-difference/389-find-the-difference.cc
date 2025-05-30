#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<char> chars(26, 0);

        for (auto c: s) ++chars[c - 'a'];
        for (auto c: t) {
            if (--chars[c - 'a'] < 0) {
                return c;
            }
        }
        return ' ';
    }
};
