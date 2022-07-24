#include <string>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string res;

        int i = 0, n = command.size();
        while (i < n) {
            if (command[i] == 'G') {
                res += 'G';
                ++i;
            }
            
            if (command[i] == '(') {
                if (command[i+1] == ')') {
                    res += 'o';
                    i += 2;
                } else {
                    res += "al";
                    i += 4;
                }
            }
        }

        return res;
    }
};