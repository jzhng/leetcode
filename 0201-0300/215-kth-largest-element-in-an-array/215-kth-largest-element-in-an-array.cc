#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = n - 1;
        int p = 0;
        while (l <= r) {
            p = partition(nums, l, r);
            if (p == n - k) {
                break;
            } else if (p < n - k) {
                l = p + 1;
            } else {
                r = p - 1;
            }
        }
        return nums[p];
    }
private:
    int partition(vector<int>& nums, int l, int r) {
        const int v = nums[l];
        int j = l;

        for (int i = l+1; i <= r; ++i) {
            if (nums[i] < v) {
                swap(nums[i], nums[++j]);
            }
        }

        swap(nums[l], nums[j]);
        return j;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout << s.findKthLargest(nums, 4) << endl;
    return 0;
}
