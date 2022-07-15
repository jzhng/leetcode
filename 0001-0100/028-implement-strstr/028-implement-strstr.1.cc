#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if (m < n) {
            return -1;
        }

        for (int i = 0; i < m - n + 1; ++i) {
            bool match = true;
            for (int j = 0; j < n; ++j) {
                if (haystack[i+j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return i;
        }

        return -1;
    }
};

int main() {
    Solution s;
    string str = "mississippi";
    string needle = "issip";
    cout << s.strStr(str, needle) << endl;
}