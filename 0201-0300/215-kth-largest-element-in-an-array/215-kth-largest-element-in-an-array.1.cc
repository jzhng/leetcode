#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int n: nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout << s.findKthLargest(nums, 4) << endl;
    return 0;
}
