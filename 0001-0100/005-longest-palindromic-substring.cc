#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        for (int k = n; k >= 1; --k) {
            for (int i = 0; i <= n-k; ++i) {
                l = i;  r = i + k - 1;
                bool is_palindrome = true;
                while (l < r) {
                    if (s[l++] != s[r--]) {
                        is_palindrome = false;
                        break;
                    };
                }
                if (is_palindrome) {
                    return s.substr(i, k);
                }

            }
        }
        return s.substr(0, 1);
    }
};

int main() {
    Solution s;
    string str = "cbbd";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}