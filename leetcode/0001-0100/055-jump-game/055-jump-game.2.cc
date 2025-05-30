class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int next = 0;

        for (int i = 0; i < n - 1; ++i) {
            next = max(next, i + nums[i]);
            if (next <= i) return false;
        }

        return true;
    }
};
