#include <string>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for (auto &c : s) {
            if (c >= 'A' && c <= 'Z') c |= 32;
        }

        return s;
    }
};