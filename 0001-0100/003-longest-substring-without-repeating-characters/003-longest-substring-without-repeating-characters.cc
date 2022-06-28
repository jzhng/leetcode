#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), res = 0;
        unordered_set<char> chars;

        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0) chars.erase(s[i-1]);
            while (j < n && !chars.count(s[j])) {
                chars.insert(s[j++]);
            }
            cout << i << " " << j << endl;
            res = max(res, j - i);
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "dvdf";
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}
