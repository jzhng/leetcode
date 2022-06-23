#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strings;
        string str = "";
        bool digit = true;
        for (auto &c : s) {
            if (isdigit(c)) {
                if (!digit) {
                    if (str != "") {
                        strings.push(str);
                        str = "";
                    }
                    digit = true;
                }
                str += c;
            } else if (isalpha(c)) {
                if (digit) {
                    if (str != "") {
                        nums.push(stoi(str));
                        str = "";
                    }
                    digit = false;
                }
                str += c;
            } else if (c == '[') {
                if (digit) {
                    nums.push(stoi(str));
                } else {
                    strings.push(str);
                }
                str = "";
                strings.push("[");
            } else if (c == ']') {
                while (!strings.empty() && strings.top() != "[") {
                    str = strings.top() + str;
                    strings.pop();
                }
                strings.pop();
                int times = nums.top();
                nums.pop();

                string temp = "";
                for (int i = 0; i < times; ++i) {
                    temp += str;
                }
                strings.push(temp);
                str = "";
            }
        }

        string res = str;
        while (!strings.empty()) {
            res = strings.top() + res;
            strings.pop();
        }
        return res;
    }
};

int main() {
    Solution s;
    string s1 = "3[a]2[bc]";
    cout << s.decodeString(s1) << endl;
    string s2 = "3[a2[c]]";
    cout << s.decodeString(s2) << endl;
    string s3 = "2[abc]3[cd]ef";
    cout << s.decodeString(s3) << endl;
    string s4 = "3[a]2[b4[F]c]";
    cout << s.decodeString(s4) << endl;
    return 0;
}