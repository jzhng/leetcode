#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        stack<int> st;
        unordered_map<int, int> gt;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }
            gt[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        vector<int> res;
        for (int i = 0 ; i < m; ++i) {
            res.push_back(gt[nums1[i]]);
        }
        return res;
    }
};
