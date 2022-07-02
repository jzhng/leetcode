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

        int cnt = 0;
        for (auto &n: freq) {
            ++cnt;
            if (cnt > k) {
                if (pq.top().second < n.second) {
                    pq.pop();
                    pq.push(n);
                }
            } else {
                pq.push(n);
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            res.emplace_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
