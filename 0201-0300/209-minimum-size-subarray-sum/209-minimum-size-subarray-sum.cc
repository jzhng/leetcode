#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, sum = 0;
        
        int min = 0;
        while (r < nums.size()) {
            sum += nums[r];
            if (sum >= target) {
                if (min == 0) min = r - l + 1;
                while (sum >= target + nums[l]) {
                   sum -= nums[l++];
                }
                if (r - l  + 1 < min) min = r -l + 1;
            }
            r++;
        }
        return min;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << s.minSubArrayLen(7, nums) << endl;
}