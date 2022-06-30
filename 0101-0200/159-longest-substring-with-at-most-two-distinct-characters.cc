#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0, r = 0;
        unordered_map<char, int> hm;

        while (r < s.size()) {
            hm[s[r]]++;
            if (hm.size() > 2) {
                if (--hm[s[l]] == 0) hm.erase(s[l]);
                ++l;
            }
            ++r;
        }
        return r - l;
    }
};

int main() {
    Solution s;
    std::cout << s.lengthOfLongestSubstringTwoDistinct("eceba") << std::endl;
    std::cout << s.lengthOfLongestSubstringTwoDistinct("ccaabbb") << std::endl;
    return 0;
}
