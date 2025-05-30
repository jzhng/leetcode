#include <iostream>
using namespace std;

typedef unsigned int uint32_t;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & (1 << i)) ++res;
       }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.hammingWeight(11) << endl;
    return 0;
}