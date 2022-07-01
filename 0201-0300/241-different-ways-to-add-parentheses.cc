#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
   unordered_map<string, vector<int>> mp;

public:
    vector<int> diffWaysToCompute(string expression) {
        if (mp.count(expression)) {
            return mp[expression];
        }

        vector<int> res;

        auto found = expression.find_first_of("+-*");
        if (found == string::npos) {
            res.push_back(stoi(expression));
        }

        while (found != string::npos) {
            auto v1 = diffWaysToCompute(expression.substr(0, found));
            auto v2 = diffWaysToCompute(expression.substr(found+1, expression.size() - 1 - found));

            char c = expression[found];
            for (auto n1: v1) {
                for (auto n2: v2) {
                    if (c == '+') {
                        res.emplace_back(n1 + n2);
                    } else if (c == '-') {
                        res.emplace_back(n1 - n2);
                    } else {
                        res.emplace_back(n1 * n2);
                    }
                }
            }
            found = expression.find_first_of("+-*", found + 1);
        }

        mp[expression] = res;

        return res;
    }
};
