#include <string>
#include <vector>
using namespace std;

class Solution {
    void dfs(int i, int n, string t, string &s, vector<string> &res) {
        if (i == n) {
            res.push_back(t);
            return;
        }

        if (isdigit(s[i])) {
            dfs(i+1, n, t+s[i], s, res);
        }

        if (isalpha(s[i])) {
            dfs(i+1, n, t+(char)tolower(s[i]), s, res);
            dfs(i+1, n, t+(char)toupper(s[i]), s, res);
        }
    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string t;
        int n = s.size();
        dfs(0, n, t, s, res);
        return res;
    }
};