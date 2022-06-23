#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        set<int> visited;

        q.push(0);
        while (!q.empty()) {
            int r = q.front();
            q.pop();
            visited.insert(r);
            for (auto n: rooms[r]) {
                if (visited.count(n) == 0) q.push(n);
            }
        }
        return visited.size() == rooms.size();
    }
};

int main() {
    Solution s;
    vector<vector<int>> rooms = {
        {1,3},
        {3,0,1},
        {2},
        {0},

    };
    cout << s.canVisitAllRooms(rooms) << endl;
    return 0;
}