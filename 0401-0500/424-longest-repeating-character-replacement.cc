#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26] = {0};

        int curr = 0, l = 0, r = 0;
        while (r < s.size()) {
            curr = max(curr, ++cnt[s[r] - 'A']);
            if (r - l + 1 > curr + k) {
                --cnt[s[l] - 'A'];
                ++l;
            }
            ++r;
        }
        return r - l;
    }
};
