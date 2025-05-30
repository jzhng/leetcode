class Solution {
    vector<vector<int>> res;
    vector<int> nums;

    void backtracking(vector<int>& candidates, int target) {
        if (target == 0) {
            res.push_back(nums);
            return;
        }

        for (int i = 0; i < candidates.size() && target >= candidates[i]; ++i) {
            if (nums.empty() || candidates[i] >= nums.back()) {
                nums.push_back(candidates[i]);
                target -= candidates[i];
                backtracking(candidates, target);
                target += candidates[i];
                nums.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target);
        return res;
    }
};