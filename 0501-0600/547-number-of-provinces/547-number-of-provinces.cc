class Solution {
    void dfs(int i, vector<vector<int>> &isConnected, vector<bool> &vis) {
        vis[i] = true;

        int n = isConnected.size();
        for (int j = 0; j < n; ++j) {
            if (i != j && isConnected[i][j] && !vis[j]) {
                dfs(j, isConnected, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), res = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ++res;
                dfs(i, isConnected, vis);
            }
        }

        return res;
    }
};
