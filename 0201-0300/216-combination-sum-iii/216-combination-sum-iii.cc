class Solution {
    vector<vector<int>> res;
    vector<int> nums;

    void backtracking(int start, int &sum, int k, int n) {
        if (nums.size() == k && sum == n) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i <= n - sum && i <= 9; ++i) {
            nums.push_back(i);
            sum += i;
            backtracking(i+1, sum, k, n);
            sum -= i;
            nums.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = 0;
        backtracking(1, sum, k, n);
        return res;
    }
};
