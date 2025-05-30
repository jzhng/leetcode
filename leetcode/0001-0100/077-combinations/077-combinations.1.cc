#include <vector>
using namespace std;

class Solution {
    vector<int> nums;
    vector<vector<int>> res;
    void dfs(int curr, int n, int k) {
        if (nums.size() == k) {
            res.push_back(nums);
            return;
        }

        if (curr == n + 1) {
            return;
        }

        nums.push_back(curr);
        dfs(curr+1, n, k);
        nums.pop_back();
        dfs(curr+1, n, k);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }
};