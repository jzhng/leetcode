class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;

        int p = 0, q = 1, r = 0;
        for (int i = 2; i <= n; ++i) {
            r = p + q;
            p = q;
            q = r;
        }
        return r;
    }
};
