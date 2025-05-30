#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1;

    while (l < r) {
      int sum = numbers[l] + numbers[r];
      if (sum < target) {
        l++;
      } else if (sum > target) {
        r--;
      } else {
        return {l + 1, r + 1};
      }
    }
    return {0, 0};
  }
};

int main() {
  Solution s;
  vector<int> nums = {2, 7, 11, 15};
  vector<int> res = s.twoSum(nums, 9);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}
