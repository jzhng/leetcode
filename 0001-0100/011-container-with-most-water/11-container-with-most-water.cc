#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), l = 0, r = n - 1;
        
        int area = 0;
        while (l < r) {
            area = max(area, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return area;
    }
};

int main() {
    Solution s;
    vector<int> height = {1, 2, 4, 3};
    cout << s.maxArea(height) << endl;
    return 0;
}