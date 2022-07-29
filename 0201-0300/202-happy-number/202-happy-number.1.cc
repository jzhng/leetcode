#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n < 0) return false;
        set<int> numbers;

        while (n != 1) {
            if (numbers.count(n) != 0) {
                return false;
            } else {
                numbers.insert(n);
            }
            int sum = 0;
            while (n) {
                int t = n % 10;
                sum += t * t;
                n /= 10;
            }
            n = sum;
        }

        return true;
    }
};
