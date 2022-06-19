#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> res;
        for (int i = 0; i < m+n-1; ++i) {
            if (i % 2 == 0) {
                int k = i < m - 1 ? i : m - 1;
                for (int j = k; j >= 0 && j >= i-n+1; --j) {
                    res.push_back(mat[j][i-j]);
                }
            } else {
                int k = i < n - 1 ? 0 : i - n + 1;
                for (int j = k; j < m && j <= i; ++j) {
                    res.push_back(mat[j][i-j]);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{1,2,3},{4,5,6}, {7,8,9}};
    vector<int> res = s.findDiagonalOrder(mat);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}