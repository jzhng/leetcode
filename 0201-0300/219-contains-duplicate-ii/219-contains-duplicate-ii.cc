#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> indexes;
        for (int i = 0; i < nums.size(); ++i) {
            if (indexes.count(nums[i]) && i - indexes[nums[i]] <=k) {
                return true;
            }
            indexes[nums[i]] = i;
        }
        return false;
    }
};
