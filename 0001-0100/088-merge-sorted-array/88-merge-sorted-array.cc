#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int k = m + n -1, i = m - 1, j = n - 1;
    nums1.resize(k+1);
    while (k >= 0) {
        if (i < 0) {
            nums1[k--] = nums2[j--];
        } else if (j < 0) {
            nums1[k--] = nums1[i--];
        } else if (nums1[i] < nums2[j]) {
            nums1[k--] = nums2[j--];
        } else {
            nums1[k--] = nums1[i--];
        }
    }
  }
};

int main() {
  Solution s;
  vector<int> nums1 = {0};
  vector<int> nums2 = {1};
  s.merge(nums1, 0, nums2, 1);
  for (auto& n : nums1) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
