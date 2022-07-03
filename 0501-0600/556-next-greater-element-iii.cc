#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while (n) {
            digits.emplace_back(n % 10);
            n /= 10;
        }

        int nn = digits.size();
        for (int l = 0, r = nn - 1; l < r; ++l, --r) {
            swap(digits[l], digits[r]);
        }

        for (int i = nn - 2; i >= 0; --i) {
            int min = 10, minIndex = -1;
            for (int j = i + 1; j < nn; ++j) {
                if (digits[i] < digits[j]) {
                    if (digits[j] < min) {
                        min = digits[j];
                        minIndex = j;
                    }
                }
            }
            if (minIndex != -1) {
                long res = 0;
                vector<int> t(digits);
                swap(t[i], t[minIndex]);
                sort(t.begin() + i +1, t.end());
                for (int k = 0; k < nn; ++k) {
                    res = res * 10 + t[k];
                }
                if (res <= INT_MAX) {
                    return (int) res;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.nextGreaterElement(12) << endl;
    return 0;
}