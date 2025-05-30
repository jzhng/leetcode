#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (x < arr[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        int p = l - 1;
        if (p == -1 || (p < n-1 && arr[p+1] - x < x - arr[p])) {
            ++p;
        }
        l = r = p;
        int cnt = 1;
        while (cnt < k) {
            if (l == 0) {
                ++r;
            } else if (r == n - 1) {
                --l;
            } else {
                if (abs(x-arr[l-1]) <= abs(x-arr[r+1])) {
                    --l;
                } else {
                    ++r;
                }
            }
            ++cnt;
        }
        
        vector<int> res;
        for (int i = l; i <= r; ++i) {
            res.push_back(arr[i]);
        }
        return res;
    }
};