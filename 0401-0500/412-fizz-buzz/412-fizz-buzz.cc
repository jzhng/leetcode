#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                result.push_back("FizzBuzz");
            } else if (i % 5 == 0) {
                result.push_back("Buzz");
            } else if (i % 3 == 0) {
                result.push_back("Fizz");
            } else {
                result.push_back(to_string(i));
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> result = s.fizzBuzz(15);
    for (auto &str: result) {
        cout << str << " ";
    }
    cout << endl;
}