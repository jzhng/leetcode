#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for (auto &account: accounts) {
            int sum = 0;
            for (auto &money: account) {
                sum += money;
            }
            if (max < sum) max = sum;
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<vector<int>> accounts = {{1,2,3},{4,5,6},{7,8,9}};
    cout << s.maximumWealth(accounts) << endl;
    return 0;
}