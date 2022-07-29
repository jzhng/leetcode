class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        int m = s.size(), n = p.size();
        if (m < n) return res;

        unordered_map<char, int> mp;
        for (char c: p) ++mp[c];

        for (int i = 0; i < n; ++i) {
            if (--mp[s[i]] == 0) mp.erase(s[i]);
        }

        if (mp.empty()) res.push_back(0);
        for (int i = 0, j = n; j < m; ++i, ++j) {
            if (++mp[s[i]] == 0) mp.erase(s[i]);
            if (--mp[s[j]] == 0) mp.erase(s[j]);
            if (mp.empty()) res.push_back(i + 1);
        }

        return res;
    }
};
