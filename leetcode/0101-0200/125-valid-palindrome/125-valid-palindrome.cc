#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      while (l < r && !isalnum(s[l])) l++;
      while (l < r && !isalnum(s[r])) r--;
      if (tolower(s[l]) != tolower(s[r])) return false;
      l++;
      r--;
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isPalindrome("\"0P\"") << endl;
  return 0;
}
