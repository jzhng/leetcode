class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 1;

        int preDiff = 0, currDiff = 0;
        for (int i = 1; i < nums.size(); ++i) {
            currDiff = nums[i] - nums[i-1];
            if (currDiff > 0 && preDiff <= 0 ||
                currDiff < 0 && preDiff >= 0) {
                ++res;
                preDiff = currDiff;
            }
        }

        return res;

    }
};