#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size();
        while (l < r) {
            int mid = l + (r-l) / 2;
            if (target < letters[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l == letters.size() ? letters[0] : letters[l];
    }
};