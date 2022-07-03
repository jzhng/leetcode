#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<char, int> mp;
    auto isSorted(const string &w1, const string &w2) -> bool {
        int n1 = w1.size(), n2 = w2.size();
        int i = 0;
        for(; i < n1 && i < n2; ++i) {
            if (mp[w1[i]] < mp[w2[i]]) {
                return true;
            } else if (mp[w1[i]] > mp[w2[i]]) {
                return false;
            }
        }

        return (i == n1);
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); ++i) {
            mp[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            int n1 = words[i].size(), n2 = words[i+1].size();
            
            if (!isSorted(words[i], words[i+1])) {
                return false;
            }
        }

        return true;
    }
};