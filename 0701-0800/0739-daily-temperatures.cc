#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int nt = temperatures.size();
        vector<int> res(nt, 0);
        stack<int> stk;
        for (int i = 0; i < nt; ++i) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int t = stk.top();
                res[t] = i - t;
                stk.pop();
            }
            stk.push(i);
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