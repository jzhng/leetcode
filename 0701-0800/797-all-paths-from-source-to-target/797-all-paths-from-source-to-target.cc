class Solution {
    vector<vector<int>> res;

    void dfs(int i, vector<int> &path, vector<vector<int>> & graph) {
        if (i == graph.size() - 1) {
            res.push_back(path);
            return;
        }

        for (int j : graph[i]) {
            path.push_back(j);
            dfs(j, path, graph);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        path.push_back(0);
        dfs(0, path, graph);
        return res;
    }
};
