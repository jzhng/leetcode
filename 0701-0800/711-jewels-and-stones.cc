#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;

        for (auto c: jewels) st.insert(c);

        int cnt = 0;
        for (auto c: stones) {
            if (st.count(c)) ++cnt;
        }

        return cnt;
    }
};