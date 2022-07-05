#include <vector>
#include <climits>
using namespace std;

class Solution {
    long merge(vector<int>& nums, int n, int l, int m, int r) {
        int nl = m - l, nr = r - m;
        vector<long> left(nums.begin() + l, nums.begin() + m);
        vector<long> right(nums.begin() + m, nums.begin() + r);
        left.push_back(LONG_MAX);
        right.push_back(LONG_MAX);

        long cnt = 0;
        int i = 0, j = 0;
        for (int k = l; k < r; ++k) {
            if (left[i] <= right[j]) {
                nums[k] = left[i++];
            } else {
                nums[k] = right[j++];
                cnt += nl - i;
            }
        }
        return cnt;
    }

    long mergeSort(vector<int>& nums, int n, int l, int r) {
        if (l + 1 < r) {
            int mid = (l + r) / 2;
            int v1 = mergeSort(nums, n, l, mid);
            int v2 = mergeSort(nums, n, mid, r);
            int v3 = merge(nums, n, l, mid, r);
            return v1 + v2 + v3;
        }
        return 0;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        long res = mergeSort(nums, n, 0, n);
        return res;
    }
};