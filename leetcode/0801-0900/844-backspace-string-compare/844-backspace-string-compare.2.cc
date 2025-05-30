#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.size() - 1, n = t.size() - 1;
        while (m >= 0 || n >= 0) {
            int cnt = 0;
            while (m >= 0) {
                if (s[m] == '#') {
                    ++cnt;
                } else if (cnt > 0) {
                    --cnt;
                } else {
                    break;
                }
                --m;
            }

            cnt = 0;
            while (n >= 0) {
                if (t[n] == '#') {
                    ++cnt;
                } else if (cnt > 0) {
                    --cnt;
                } else {
                    break;
                }
                --n;
            }

            if (m >= 0 && n >= 0) {
                if (s[m] != t[n]) return false;
            } else if (m >= 0 || n >= 0) {
                return false;
            }
            
            --m; --n;
        }

        return true;
    }
};