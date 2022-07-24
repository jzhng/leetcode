class Solution {
    double pow(double x, long n) {
        if (n == 0) return 1.0;

        double y = pow(x, n/2);
        return n % 2 ? y * y * x : y * y;
    }
public:
    double myPow(double x, int n) {
        long nl = n;
        if (nl < 0) {
            return 1.0 / pow(x, -nl);
        }
        return pow(x, nl);
    }
};