#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<string> strs(n+1);
        strs[1] = "1";

        for (int i = 2; i <= n; ++i) {
            string s = strs[i-1], t = "";
            
            int cnt = 0, n = s.size();
            int l = 0;
            while (l < n) {
                int r = l + 1;
                while (r < n && s[r] == s[r-1]) ++r;
                t += to_string(r-l);
                t += s[l];
                l = r;
            }

            strs[i] = t;
        }

        return strs[n];
    }
};
