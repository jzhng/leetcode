#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    q.push({i, j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        int row, col;
                        auto rc = q.front();
                        row = rc.first, col =rc.second;
                        if (row-1 >= 0 && grid[row-1][col] == '1') {
                            q.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if (row+1 < m && grid[row+1][col] == '1') {
                            q.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if (col-1 >= 0 && grid[row][col-1] == '1') {
                            q.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col+1 < n && grid[row][col+1] == '1') {
                            q.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                        q.pop();
                    }
                    ++cnt;
                } 
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << s.numIslands(grid) << endl;
    return 0;
}