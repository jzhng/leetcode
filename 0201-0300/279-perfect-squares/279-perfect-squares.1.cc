#include <iostream>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        set<int> visited;
        int level = 0;
        q.push(0);

        while (!q.empty()) {
            ++level;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int d = q.front();
                q.pop();
                for (int j = 1; ; ++j) {
                    int v = d + j * j;
                    if (v < n && visited.count(v) != 1) {
                        q.push(v);
                        visited.insert(v);
                    }
                    if (v == n) return level;
                    if (v > n) break;
                }                
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.numSquares(12) << endl;
}