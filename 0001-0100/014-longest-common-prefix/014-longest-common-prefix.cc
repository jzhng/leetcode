#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        string first = strs[0];
        int j = 0;
        bool mismatch = false;
        while (j < first.length() && !mismatch) {
            char c = first[j];
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i][j] != c) {
                    mismatch = true;
                    break;
                }
            }
            if (!mismatch) prefix += c;
            j++;
        }
        return prefix;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
