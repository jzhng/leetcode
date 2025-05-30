#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for (auto n: nums1) {
            s.insert(n);
        }

        unordered_set<int> t;
        for (auto n: nums2) {
            if (s.count(n) == 1) {
                t.insert(n);
            }
        }
        
        vector<int> res(t.begin(), t.end());
        return res;
    }
};
