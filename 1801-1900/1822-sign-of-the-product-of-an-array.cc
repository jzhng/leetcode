#include <vector>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negative = 0;
        for (auto n: nums) {
            if (n == 0) {
                return 0;
            } else if (n < 0) {
                ++negative;
            }
        }

        return (negative % 2 == 1 ? 1 : -1);
    }
};
