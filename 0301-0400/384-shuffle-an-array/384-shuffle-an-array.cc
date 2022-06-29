#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
    vector<int> nums;
    vector<int> shuffled;
public:
    Solution(vector<int>& nums): nums(nums), shuffled(nums) {}
    
    vector<int> reset() {
        shuffled = nums;
        return shuffled;
    }
    
    vector<int> shuffle() {
        int n = shuffled.size();
        for (int i = n - 1; i >= 0; --i) {
            int index = rand() % (i + 1);
            swap(shuffled[i], shuffled[index]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
