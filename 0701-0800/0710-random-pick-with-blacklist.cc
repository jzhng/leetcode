#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
using namespace std;

class Solution {
    unordered_map<int, int> m;
    int bound;
public:
    Solution(int n, vector<int>& blacklist) {
        int nb = blacklist.size();
        bound = n - nb;
        unordered_set<int> black;
        for (auto v: blacklist) {
            if (v >= bound) {
                black.insert(v);
            }
        }

        int w = bound;
        for (auto v: blacklist) {
            if (v < bound) {
                while (black.count(w)) {
                    ++w;
                }
                m[v] = w++;
            }
        }
    }
    
    int pick() {
        int res = rand() % bound;
        return (m.count(res) ? m[res] : res);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
