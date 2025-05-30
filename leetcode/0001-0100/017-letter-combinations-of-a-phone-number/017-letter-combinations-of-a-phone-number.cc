class Solution {
    vector<string> mp = { 
               "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    vector<string> res;
    string s;

    void backtracking(string &digits, int i) {
        if (digits == "") return;

        if (digits.size() == i) {
            res.push_back(s);
            return;
        }

        for (char c: mp[digits[i] - '2']) {
            s.push_back(c);
            backtracking(digits, i + 1);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        backtracking(digits, 0);
        return res;
    };
};