#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isvowel(s[l])) l++;
            while (l < r && !isvowel(s[r])) r--;
            swap(s[l++], s[r--]);
        }
        return s;
    }
private:
    bool isvowel(char c) {
        return (
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'
        );
    }
};

int main() {
    Solution s;
    cout << s.reverseVowels("leetcode") << endl;
    return 0;
}