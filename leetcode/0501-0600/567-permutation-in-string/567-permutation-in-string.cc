#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false;

        vector<int> cnt(26);
        for (char c: s1) ++cnt[c - 'a'];

        int l = 0;
        for (int r = 0; r < n; ++r) {
            int x = s2[r] - 'a';
            --cnt[x];
            while (cnt[x] < 0) {
                ++cnt[s2[l] - 'a'];
                ++l;
            }
            if (r - l + 1 == m) return true;
        }

        return false;
    }
};
