class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while (n) {
            int d = n % 10;
            sum += d;
            product *= d;
            n = n / 10;
        }
        return product - sum;
    }
};