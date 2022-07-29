#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
    vector<int> origin;
    vector<int> nums;
public:
    Solution(vector<int>& nums) : origin(nums), nums(nums) {}
    
    vector<int> reset() {
        nums = origin;
        return nums;
    }
    
    vector<int> shuffle() {
        for (int i = nums.size() - 1; i >= 0; --i) {
            int j = rand() % (i + 1);
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
