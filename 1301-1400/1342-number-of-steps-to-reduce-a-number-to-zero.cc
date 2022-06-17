#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while (num) {
            if (num % 2) {
                num -= 1;
            } else {
                num >>= 1;
            }
            ++cnt;
        }
        return cnt;
    }
};


int main() {
    Solution s;
    cout << s.numberOfSteps(14) << endl;
    return 0;
}
