class Solution {
    vector<string> res;

    void dfs(string &s, string ip, int start, int k) {
        if (k > 4) return;

        if (start == s.size() && k == 4) {
            res.push_back(ip.substr(0, ip.size()-1));
            return;
        }

        for (int i = start; i < s.size() && i < start + 3; ++i) {
            if (s[start] == '0' && i > start) break;
            string num = s.substr(start, i - start + 1);
            if (stoi(num) < 256) {
                dfs(s, ip + num + ".", i + 1, k + 1);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s, "", 0, 0);
        return res;
    }
};