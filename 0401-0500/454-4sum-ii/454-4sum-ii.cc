#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt = 0;
        unordered_map<int, int> sums12;
        for (auto n1: nums1) {
            for (auto n2: nums2) {
                ++sums12[n1+n2];
            }
        }

        for (auto n3: nums3) {
            for (auto n4: nums4) {
                auto it = sums12.find(-n3-n4);
                if (it != sums12.end()) cnt += it->second;
            }
        }

        return cnt;
    }
};