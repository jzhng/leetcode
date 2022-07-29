class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int m = firstList.size(), n = secondList.size(), i = 0, j = 0;

        while (i < m && j < n) {
            int starti = firstList[i][0], endi = firstList[i][1];
            int startj = secondList[j][0], endj = secondList[j][1];

            if (endi < startj) {
                ++i;
                continue;
            }

            if (endj < starti) {
                ++j;
                continue;
            }

            int x = max(starti, startj);
            int y = min(endi, endj);

            if (y == endi) {
                ++i;
            } else {
                ++j;
            }

            res.push_back({x, y});
        }

        return res;
    }
};
