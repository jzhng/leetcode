class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            hash[s[i] - 'a'] = i;
        }

        vector<int> res;
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); ++i) {
            r = max(r, hash[s[i] - 'a']);
            if (r == i) {
                res.push_back(r - l + 1);
                l = i + 1;
            }
        }
        return res;

    }
};
