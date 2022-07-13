class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (num <= (long)mid * mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return (long)l * l == num;
    }
};