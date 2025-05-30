class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int cnt = 0;
        for (int i = g.size() - 1, j = s.size() - 1; i >=0 && j>= 0; --i) {
            if (s[j] >= g[i]) {
                --j;
                ++cnt;
            }
        }
        return cnt;
    }
};
