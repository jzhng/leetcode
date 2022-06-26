#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, n = s.size();
        while (i < n) {
            int l = i;
            while (i < n && s[i] != ' ') ++i;

            for (int r = i - 1; l < r; ++l, --r) {
                swap(s[l], s[r]);
            }

            while (i < n && s[i] == ' ') ++i;
        }
        return s;
    }
};

int  main() {
    Solution s;
    // string str = "Let's take LeetCode contest";
    string str = "God Ding";
    cout << s.reverseWords(str) << endl;
    return 0;
}
