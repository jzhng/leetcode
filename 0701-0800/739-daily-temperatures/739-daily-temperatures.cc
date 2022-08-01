#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int t = st.top();
                res[t] = i - t;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = s.dailyTemperatures(temperatures);
    for (auto & i: res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}