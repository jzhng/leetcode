#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        set<string> operators;
        operators.insert("+");
        operators.insert("-");
        operators.insert("*");
        operators.insert("/");

        for (auto & token: tokens) {
            if (operators.count(token) == 0) {
                operands.push(stoi(token));
            } else {
                int operand_a = operands.top();
                operands.pop();
                int operand_b = operands.top();
                operands.pop();
                int res;
                if (token == "+") {
                    res = operand_a + operand_b;
                } else if (token == "-") {
                    res = operand_b - operand_a;
                } else if (token == "*") {
                    res = operand_a * operand_b;
                } else {
                    res = operand_b / operand_a;
                }
                operands.push(res);
            }
        }
        return operands.top();
    }
};

int main() {
    Solution s;
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    cout << s.evalRPN(tokens) << endl;
}