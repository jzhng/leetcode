#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hm;

        for (auto &s : strings) {
            string key = s;
            char k = key[0] - 'a';
            for (auto &c: key) {
                c -= k;
                if (c < 'a') c += 26;
            }
            hm[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto [key, value] : hm) res.emplace_back(value);

        return res;
    }
};
