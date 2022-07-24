class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;

        auto cmp = [](vector<int> &a, vector<int> &b) -> bool {
            return a[1] < b[1];
        };

        sort(intervals.begin(), intervals.end(), cmp);
    
        int cnt = 1, end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (end <= intervals[i][0]) {
                end = intervals[i][1];
                ++cnt;
            }
        }
        return intervals.size() - cnt;
    }
};
