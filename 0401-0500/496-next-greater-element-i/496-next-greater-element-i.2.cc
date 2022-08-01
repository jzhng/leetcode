class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(m, -1);

        unordered_map<int, int> mp;
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        for (int i = 0; i < m; ++i) {
            res[i] = mp.count(nums1[i]) ? mp[nums1[i]] : -1;
        }

        return res;
    }
};