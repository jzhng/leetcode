#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, res = 0, sign = 1;
        int n = s.size();
        
        while (s[i] == ' ' && i < n) ++i;
        if (i == n) return 0;

        if (s[i] == '-' || s[i] == '+') {
            sign = s[i] == '-' ? -1 : 1;
            ++i;
        }

        while (isdigit(s[i]) && i < n) {
            int digit = s[i] - '0';
            if (res > INT_MAX / 10 ||
                res == INT_MAX / 10 && digit > INT_MAX % 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + digit;
            ++i;
        }
        return res * sign;
    }
};

int main() {
    Solution s;
    string str = "   -42";
    cout << s.myAtoi(str) << endl;
    string str2 = "4193 with words";
    cout << s.myAtoi(str2) << endl;
    string str3 = "words and 987";
    cout << s.myAtoi(str3) << endl;
    string str4 = "-91283472332";
    cout << s.myAtoi(str4) << endl;
    string str5 = "   +";
    cout << s.myAtoi(str5) << endl;
    string str6 = "   +   ";
    cout << s.myAtoi(str6) << endl;
    string str7 = "2147483648";
    cout << s.myAtoi(str7) << endl;
    string str8 = "2147483647";
    cout << s.myAtoi(str8) << endl;
    string str9 = "-2147483648";
    cout << s.myAtoi(str9) << endl;
    string str10 = "-2147483649";
    cout << s.myAtoi(str10) << endl;
    return 0;
}

