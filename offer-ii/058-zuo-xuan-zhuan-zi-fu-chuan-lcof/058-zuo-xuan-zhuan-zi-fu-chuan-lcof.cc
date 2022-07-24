#include <string>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int k) {
        auto reverse = [&s](int i, int j) mutable {
            while (i < j) swap(s[i++], s[j--]);
        };

        int n = s.size();
        reverse(0, k - 1);
        reverse(k, n - 1);
        reverse(0, n - 1);
        return s;
    }
};

class Solution {
public:
    string reverseLeftWords(string s, int k) {
        int n = s.size();
        for (int start = 0, mov = 0; mov < n; ++start) {
            char t = s[start];
            int i = start, j = (start + k) % n;
            while (j != start) {
                s[i] = s[j];
                ++mov;
                i = j;
                j = (i + k) % n;
            }
            s[i] = t;
            ++mov;
        }
        return s;
    }
};
