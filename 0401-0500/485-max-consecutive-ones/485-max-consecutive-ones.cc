#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (j < n && nums[j] == 1) ++j;
            if (j -i > res) res = j - i;
            i = j;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1};
    cout << s.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}