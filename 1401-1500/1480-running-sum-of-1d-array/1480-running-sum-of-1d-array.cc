#include <iostream>
#include <vector>
using namespace std;

// Could have reused the nums vector to store the result,
// and reduce space complexity to O(1).
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int sum = 0;
        for (auto num : nums) {
            sum += num;
            result.push_back(sum);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = s.runningSum(nums);
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;
}
