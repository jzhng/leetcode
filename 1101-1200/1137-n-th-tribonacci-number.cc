class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) return n;
        if (n == 2) return 1;

        int p = 0, q = 1, r = 1, s = 0;
        for (int i = 3; i <= n; ++i) {
            s = p + q + r;
            p = q;
            q = r;
            r = s;
        }
        return s;
    }
};
