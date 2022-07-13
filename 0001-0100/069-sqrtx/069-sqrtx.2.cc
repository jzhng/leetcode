class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int l = 1, r = x >> 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (x < (long) mid * mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
};
