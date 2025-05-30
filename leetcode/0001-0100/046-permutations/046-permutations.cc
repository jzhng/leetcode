#include <vector>
using namespace std;

class Solution {
    void dfs(int len, int n,
        vector<bool> &used,
        vector<int> &permutation,
        vector<vector<int>> &res,
        vector<int> &nums) {
        if (len == n) {
            res.push_back(permutation);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                permutation.push_back(nums[i]);
                used[i] = true;
                dfs(len+1, n, used, permutation, res, nums);
                permutation.pop_back();
                used[i] = false;
            }
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n, false);
        vector<vector<int>> res;
        vector<int> permutation;

        dfs(0, n, used, permutation, res, nums);
        return res;
    }
};