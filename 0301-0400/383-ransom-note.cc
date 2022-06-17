#include <iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        
        int cnt[26] = {0};
        for (auto &c : magazine) {
            ++cnt[c - 'a'];
        }
        for (auto &c : ransomNote) {
            if (--cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.canConstruct("a", "a") << endl;
    return 0;
}
