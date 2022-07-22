#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> res;
    void backtracking(vector<int> &combination, int l, int r, int k) {
        if (combination.size() == k) {
            res.push_back(combination);
            return;
        }

        int m = r - (k - combination.size()) + 1;
        for (int i = l; i <= m; ++i) {
            combination.push_back(i);
            backtracking(combination, i + 1, r, k);
            combination.pop_back();
        }

    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        backtracking(combination, 1, n, k);    
        return res;
    }
};