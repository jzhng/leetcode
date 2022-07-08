#include <vector>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        int odd = 0;
        for (auto p: position) {
            if (p % 2) ++odd;
        }
        return min(odd, n - odd);
    }
};