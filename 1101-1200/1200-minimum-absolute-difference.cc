#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> diffs;
        
        int minDiff = 2000000;
        for (int i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i-1];
            minDiff = min(minDiff, diff);
            diffs.push_back(diff);
        }

        vector<vector<int>> res;
        for (int i = 0; i < diffs.size(); ++i) {
            if (diffs[i] == minDiff) {
                res.push_back({arr[i], arr[i+1]});
            }
        }
        return res;
    }
};