#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ' ') {
                for (int k = i, l = j-1; k < l; ++k, --l)
                    swap(s[k], s[l]);
                i = j+1;
            }
        }
        for (int j = i, l = s.size()-1; j < l; ++j, --l)
            swap(s[j], s[l]);
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