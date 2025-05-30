#include <vector>
using namespace std;

class Solution {
    void mergeSort(vector<pair<int, int>> &arr, int l, int r, vector<int> &res) {
        if (l + 1 >= r) return;

        int mid = (l + r) /2;
        mergeSort(arr, l, mid, res);
        mergeSort(arr, mid, r, res);

        int i = 0, j = mid - l, k = l;
        vector<pair<int, int>> t(arr.begin()+l, arr.begin()+r);
        while (i < mid - l || j < r - l) {
            if (j == r - l || (i < mid - l && t[i].second <= t[j].second)) {
                res[t[i].first] += j - mid + l;
                arr[k++] = t[i++];
            } else {
                arr[k++] = t[j++];
            }
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({i, nums[i]});
        }
        mergeSort(arr, 0, n, res);
        return res;
    }
};