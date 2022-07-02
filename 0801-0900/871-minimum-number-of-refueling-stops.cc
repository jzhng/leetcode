#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int fuel = startFuel, loc = 0, res = 0;

        int i = 0;
        while (loc < target) {
            if (fuel == 0) {
                if (!pq.empty()) {
                    ++res;
                    fuel = pq.top();
                    pq.pop();
                } else {
                    return -1;
                }
            }

            loc += fuel;
            fuel = 0;
            while (i < stations.size() && loc >= stations[i][0]) {
                pq.push(stations[i][1]);
                ++i;
            }
        }
        return res;
    }
};