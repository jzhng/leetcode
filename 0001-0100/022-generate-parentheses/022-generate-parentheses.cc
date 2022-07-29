class Solution {
    vector<string> res;

    void generateParenthesis(int l, int r, string &s, int n) {
        if (l == n && r == n) {
            res.push_back(s);
            return;
        }

        if (l < n) {
            s.push_back('(');
            generateParenthesis(l+1, r, s, n);
            s.pop_back();
        }

        if (l > r && r < n) {
            s.push_back(')');
            generateParenthesis(l, r+1, s, n);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string s;
        generateParenthesis(0, 0, s, n);
        return res;
    }
};
