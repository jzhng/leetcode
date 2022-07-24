#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void fill(vector<vector<int>>& image, int i, int j, int color, int c) {
        int m = image.size();
        int n = image[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (c == color) return;

        if (image[i][j] == c) {
            image[i][j] = color;
            fill(image, i+1, j, color, c);
            fill(image, i-1, j, color, c);
            fill(image, i, j-1, color, c);
            fill(image, i, j+1, color, c);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int c = image[sr][sc];

        fill(image, sr, sc, color, c);
        return image;
    }
};