class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int l = 0, r = m * n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int i = mid / n, j = mid % n;
            if (matrix[i][j] == target) {
                return true;
            } else if (target < matrix[i][j]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }
};
