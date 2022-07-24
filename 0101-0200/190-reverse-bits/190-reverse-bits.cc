#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        int i = 32;
        while (i) {
            res = (res << 1) + n % 2;
            n = n >> 1;
            --i;
        }

        return res;
    }
};
