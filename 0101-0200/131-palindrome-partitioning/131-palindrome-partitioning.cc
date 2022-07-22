class Solution {
    vector<vector<string>> res;
    vector<string> palindrome;

    bool isPalindrome(string &s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) return false;
            ++l; --r;
        }
        return true;
    }

    void backtracking(string &s, int start) {
        if (start == s.size()) {
            res.push_back(palindrome);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                palindrome.push_back(s.substr(start, i - start + 1));
                backtracking(s, i + 1);
                palindrome.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};