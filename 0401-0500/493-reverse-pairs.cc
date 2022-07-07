#include <vector>
using namespace std;

class Solution {
    void mergeSort(vector<int> &nums, int l, int r, int &cnt) {
        if (l + 1 >= r) return;
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid, cnt);
        mergeSort(nums, mid, r, cnt);

        for (int i = l, j = mid; i < mid && j < r;) {
            if ((long) nums[i] > (long) 2 * nums[j]) {
                cnt += mid - i;
                ++j;
            } else {
                ++i;
            }
        }

        vector<int> t(nums.begin() + l, nums.begin() + r);
        int i = 0, j = mid - l, k = l;
        while (i < mid - l || j < r - l) {
            if (j == r - l || (i < mid -l && t[i] <= t[j])) {
                nums[k++] = t[i++];
            } else {
                nums[k++] = t[j++];
            }
        }
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        mergeSort(nums, 0, n , cnt);
        return cnt;
    }
};