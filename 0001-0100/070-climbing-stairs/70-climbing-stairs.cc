class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;

        int p = 1, q = 2, s = 0;
        for (int i = 3; i <= n; ++i) {
            s = p + q;
            p = q;
            q = s;
        }
        return s;
    }
};
