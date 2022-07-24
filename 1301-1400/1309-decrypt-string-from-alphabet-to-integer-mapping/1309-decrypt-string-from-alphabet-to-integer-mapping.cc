#include <string>
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        int i = 0, n = s.size();
        string res;

        while (i < n) {
            if (i + 2 < n && s[i+2] == '#') {
                int index = (s[i] - '0') * 10 + s[i+1] - '0' - 10;
                res += 'j' + index;
                i += 3;
            } else {
                res += ('a' + s[i] - '1');
                ++i;
            }
        }
        return res;
    }
};