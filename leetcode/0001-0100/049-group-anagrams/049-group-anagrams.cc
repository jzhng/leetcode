#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hm;

        for (auto &s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            hm[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto [key, value]: hm) {
            res.push_back(value);
        }
        return res;
    }
};
