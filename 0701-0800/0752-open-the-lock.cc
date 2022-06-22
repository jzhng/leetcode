#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> visited;

        for (auto &s : deadends) {
            visited.insert(s);
        }

        if (visited.count("0000") == 1 ||
            visited.count(target) ==1 ) {
            return -1;
        }
        if (target == "0000") return 0;

        int steps = 0;
        const int ns = target.size();
        q.push("0000");
        while (!q.empty()) {
            ++steps;
            int size = q.size();
            for (int j = 0; j < size; ++j) {
                string s = q.front();
                q.pop();
                for (int i = 0; i < ns; ++i) {
                    char t = s[i];
                    if (s[i] == '9') {
                        s[i] = '0';
                    } else {
                        ++s[i];
                    }
                    if (s == target) {
                        return steps;
                    } else {
                        if (visited.count(s) != 1) {
                            q.push(s);
                            visited.insert(s);
                        }
                    }

                    s[i] = t;
                    if (s[i] == '0') {
                        s[i] = '9';
                    } else {
                        --s[i];
                    }
                    if (s == target) {
                        return steps;
                    } else {
                        if (visited.count(s) != 1) {
                            q.push(s);
                            visited.insert(s);
                        }
                    }
                    s[i] = t;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<string> deadends = {"0000"};
    cout << s.openLock(deadends, "8888") << endl;
    return 0;
}