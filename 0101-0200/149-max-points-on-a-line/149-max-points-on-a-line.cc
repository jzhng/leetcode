class Solution {
    int gcd(int x, int y) {
        return y ? gcd(y, x % y) : x;
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0, n = points.size();
        for (int i = 0; i < n; ++i) {
            int p = 0;
            unordered_map<string, int> mp;
            for (int j = i + 1; j < n; ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int xx = x1 - x2, yy = y1 - y2;
                int k = gcd(xx, yy);
                string key = to_string(xx/k) + "_" + to_string(yy/k);
                ++mp[key];
                if (mp[key] > p) p = mp[key];
            }
            res = max(res, p + 1);
        }

        return res;

    }
};
