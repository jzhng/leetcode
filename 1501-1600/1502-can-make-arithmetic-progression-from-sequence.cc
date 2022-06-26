#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int na = arr.size(), diff = arr[1] - arr[0];
        if (na == 2) return true;
        for (int i = 1; i < na - 1; ++i) {
            if (arr[i+1] - arr[i] != diff) {
                return false;
            }
        }
        return true;
    }
};
