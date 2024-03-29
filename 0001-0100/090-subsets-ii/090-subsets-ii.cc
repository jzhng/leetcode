class Solution {
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int>& nums, int start) {
        res.push_back(path);
        if (start == nums.size()) return;

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return res;
    }
};