#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size(), j = 0;

        vector<int> next(n);
        next[0] = 0;
        for (int i = 1; i < n; ++i) {
            while (j && s[i] != s[j]) j = next[j-1];
            if (s[i] == s[j]) ++j;
            next[i] = j;
        }

        if (next[n-1] && !(n % (n - next[n-1]))) {
            return true;
        }

        return false;
    }
};