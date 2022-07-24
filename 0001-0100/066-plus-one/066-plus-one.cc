#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 0;
        ++digits[n-1];
        for (int i = n - 1; i >= 0; --i) {
            digits[i] += carry;
            if (digits[i] > 9) {
                digits[i] %= 10;
                carry = 1;
            } else {
                carry = 0;
                break;
            }
        }

        if (carry == 1) digits.insert(digits.begin(), carry);
        return digits;
    }
};
