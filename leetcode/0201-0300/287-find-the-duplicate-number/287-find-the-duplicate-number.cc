#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size(), n = len - 1;
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for (int num : nums) {
                if (num <= mid) ++cnt;
            }
            if (cnt > mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};