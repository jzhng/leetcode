#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto n: nums) {
            s.insert(n);
        }
        return s.size() < nums.size();
    }
};