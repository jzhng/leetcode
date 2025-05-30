#include <iostream>
using namespace std;

class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};

int main() {
    Solution s;
    cout << s.sum(1, 2) << endl;
    return 0;
}
