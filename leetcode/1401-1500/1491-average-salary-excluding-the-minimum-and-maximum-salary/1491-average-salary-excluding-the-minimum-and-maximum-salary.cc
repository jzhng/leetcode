#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int min = INT_MAX, max = INT_MIN, ns = salary.size();
        double sum  = 0;
        for (int i = 0; i < ns; ++i) {
            int s = salary[i];
            sum += s;
            if (min > s) min = s;
            if (max < s) max = s;
        }

        return (sum - min - max) / (ns - 2);   
    }
};