class Solution {
    vector<vector<int>> res;
    vector<int> permutation;

    void backtracking(vector<int>& nums, vector<bool> &used) {
        if (permutation.size() == nums.size()) {
            res.push_back(permutation);
            return;
        }

        bool dup[21] = {false};
        for (int i = 0; i < nums.size(); ++i) {
            if (dup[nums[i] + 10]) continue;
            if (!used[i]) {
                dup[nums[i] + 10] = true;
                used[i] = true;
                permutation.push_back(nums[i]);
                backtracking(nums, used);
                permutation.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};