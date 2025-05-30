class Solution {
    vector<vector<int>> res;
    vector<int> sequence;

    void backtracking(vector<int> &nums, int start) {
        if (sequence.size() > 1) {
            res.push_back(sequence);
        }

        bool used[201] = {false}; 
        for (int i = start; i < nums.size(); ++i) {
            if ((sequence.empty() || sequence.back() <= nums[i]) &&
                    !used[nums[i] + 100]) {
                used[nums[i] + 100] = true;
                sequence.push_back(nums[i]);
                backtracking(nums, i + 1);
                sequence.pop_back();
            }
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};