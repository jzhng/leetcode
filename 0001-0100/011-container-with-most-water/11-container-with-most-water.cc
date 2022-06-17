#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max = 0;
        while (l < r ) {
            int area = (r - l) * (height[l] > height[r] ? height[r] : height[l]);
            if (area > max) {
                max = area;
            }
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> height = {1, 2, 4, 3};
    cout << s.maxArea(height) << endl;
    return 0;
}