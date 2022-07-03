#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int m = word1.size(), n = word2.size();

        int l = min(m, n);
        for (int i = 0; i < l; ++i) {
            res += word1[i];
            res += word2[i];
        }

        res += (m > n ? word1.substr(l) : word2.substr(l));
        return res;
    }
};