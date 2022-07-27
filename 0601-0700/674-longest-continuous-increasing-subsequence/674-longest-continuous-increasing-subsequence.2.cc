class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();

        int cnt = 1, res = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] < nums[i+1]) {
                ++cnt;
            } else {
                cnt = 1;
            }
            if (cnt > res) res = cnt;
        }
        return res;
    }
};
