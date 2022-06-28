#include <vector>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n+1);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i-1] + arr[i-1];
        }

        int sum = 0;
        for (int l = 1; l <= n; l += 2) {
            for (int i = 0; i + l <= n; ++i) {
                sum += prefix[i + l] - prefix[i];
            }
        }
        return sum;
    }
};
