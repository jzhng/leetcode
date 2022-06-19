#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> strs;
        
        int n = s.size();
        int i = 0, j = 0;
        while (j < n) {
            while (s[j] == ' ' && j < n) ++j;
            i = j;
            while (s[j] != ' ' && j < n) ++j;
            if (j != n || s[j-1] != ' ') {
                strs.push_back(s.substr(i, j-i));
            }
            
        }

        string res;
        bool first = true;
        for (auto v = strs.rbegin(); v != strs.rend(); ++v) {
            if (first) {
                first = false;
            } else {
                res += ' ';
            }
            res += *v;
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "  hello world ";
    cout << s.reverseWords(str) << endl;
}