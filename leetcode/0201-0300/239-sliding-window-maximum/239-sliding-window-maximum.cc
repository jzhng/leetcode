#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();

        int i = 0;
        for ( ; i < k; ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
        }

        vector<int> res{nums[q.front()]};
        for ( ; i < n; ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            while (q.front() <= i - k) q.pop_front();
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};
