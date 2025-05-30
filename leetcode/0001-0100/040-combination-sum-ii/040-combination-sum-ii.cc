class Solution {
    vector<vector<int>> res;
    vector<int> nums;

    void backtracking(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < candidates.size() && target >= candidates[i]; ++i) {
            if (i != idx && candidates[i] == candidates[i-1])
                continue;
            nums.push_back(candidates[i]);
            target -= candidates[i];
            backtracking(candidates, target, i+1);
            target += candidates[i];
            nums.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
};