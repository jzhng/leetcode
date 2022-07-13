#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), picked = 0;
        unordered_map<int, int> mp;

        for (int l = 0, r = 0; r < n; ++r) {
            ++mp[fruits[r]];
            while (mp.size() > 2) {
                if (--mp[fruits[l]] == 0) mp.erase(fruits[l]);
                ++l;
            }
            picked = max(picked, r - l + 1);
        }

        return picked;
    }
};