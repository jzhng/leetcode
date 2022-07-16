#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();

        for (int i = 0; i < n; i += 2 * k) {
            int l = i, r = min(i + k - 1, n - 1);
            while (l < r) swap(s[l++], s[r--]);
        }
        return s;
    }
};
