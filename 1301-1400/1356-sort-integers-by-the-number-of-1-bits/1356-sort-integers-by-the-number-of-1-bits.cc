#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto compare = [](int x, int y) -> bool {
            int bx = 0, by = 0, nx = x, ny = y;
            while (nx) { ++bx; nx &= (nx-1); }
            while (ny) { ++by; ny &= (ny-1); }

            return (bx == by && x < y) || (bx < by);
        };
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};