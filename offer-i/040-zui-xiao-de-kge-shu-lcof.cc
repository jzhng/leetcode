#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.emplace_back(pq.top());
            pq.pop();
        }
        return res;
    }
};