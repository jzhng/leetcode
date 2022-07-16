#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        unordered_set<string> operators({ "+", "-", "*", "/" });

        for (auto & token: tokens) {
            if (operators.count(token) == 0) {
                st.push(stoi(token));
            } else {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int res;
                if (token == "+") {
                    res = num1 + num2;
                } else if (token == "-") {
                    res = num2 - num1;
                } else if (token == "*") {
                    res = num1 * num2;
                } else {
                    res = num2 / num1;
                }
                st.push(res);
            }
        }
        return st.top();
    }
};

int main() {
    Solution s;
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    cout << s.evalRPN(tokens) << endl;
}