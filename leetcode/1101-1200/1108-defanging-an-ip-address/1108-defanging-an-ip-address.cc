#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for (const auto &c: address) {
            if (c == '.') {
                res += "[.]";
            } else {
                res += c;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string address = "255.255.255.255";
    cout << s.defangIPaddr(address) << endl;
}

