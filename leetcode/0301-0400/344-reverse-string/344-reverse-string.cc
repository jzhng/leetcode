#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            swap(s[l], s[r]);
            ++l; --r;
        }
    }
};

int main() {
    Solution s;
    vector<char> v = {'h', 'e', 'l', 'l', 'o'};
    s.reverseString(v);
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}
