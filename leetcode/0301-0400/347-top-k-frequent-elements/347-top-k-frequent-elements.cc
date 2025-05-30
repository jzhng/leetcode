#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) ++freq[n];

        auto compare = [](pair<int, int> lhs, pair<int, int> rhs) -> bool {
            return lhs.second > rhs.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

        for (auto &item: freq) {
             pq.push(item);
            if (pq.size() > k) pq.pop();
        }

        vector<int> res;
        while (!pq.empty()) {
            res.emplace_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
