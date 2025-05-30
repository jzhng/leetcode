#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size(), j = 0;
        vector<int> next(n);

        next[0] = 0;
        for (int i = 1; i < n; ++i) {
            while (j && needle[i] != needle[j]) j = next[j-1];
            if (needle[i] == needle[j]) ++j;
            next[i] = j;
        }

        j = 0;
        for (int i = 0; i < m; ++i) {
            while (j && haystack[i] != needle[j]) j = next[j-1];
            if (needle[j] == haystack[i]) ++j;
            if (j == n) {
                return i - n + 1;
            }
        }

        return -1;
    }
};