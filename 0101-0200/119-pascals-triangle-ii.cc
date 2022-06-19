#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j > 0; --j) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = s.getRow(3);
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}