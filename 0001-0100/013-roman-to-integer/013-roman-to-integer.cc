#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman2int = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int res = 0, n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            int value = roman2int[s[i]];
            if (value < roman2int[s[i+1]]) {
                res -= value;
            } else {
                res += value;
            }
        }
        res += roman2int[s[n-1]];
        return res;
    }
};
