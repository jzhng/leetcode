#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        set<char> s;
        for (auto &r : board) {
            s.clear();
            for (auto c: r) {
                if (c != '.') {
                    if (s.count(c) == 0) {
                        s.insert(c);
                    } else {
                        return false;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            s.clear();
            for (int j = 0; j < n; ++j) {
                char c = board[j][i];
                if (c != '.') {
                    if (s.count(c) == 0) {
                        s.insert(c);
                    } else {
                        return false;
                    }
                }
            }
        }

        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                s.clear();
                for (int i = x * 3; i < x * 3 + 3; ++i) {
                    for (int j = y * 3; j < y * 3 + 3; ++j) {
                        char c = board[i][j];
                        if (c != '.') {
                            if (s.count(c) == 0) {
                                s.insert(c);
                            } else {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};
