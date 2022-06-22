#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> map = {
            {')', '('}, {']', '['}, {'}', '{'}
        };

        for (auto &c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
                continue;
            }


            if (st.empty() || st.top() != map[c]) {
                return false;
            }
            st.pop();
        }

        return st.empty();
    }
};

int main() {
    Solution s;
    string str = "()";
    cout << s.isValid(str) << endl;
}