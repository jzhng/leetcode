#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Logger {
    unordered_map<string, int> timeMap;

public:
    Logger() {};
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (!timeMap.count(message) || timeMap[message] <= timestamp) {
            timeMap[message] = timestamp + 10;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

int main() {
    Logger* obj = new Logger();
    cout << obj->shouldPrintMessage(1, "foo") << endl;
    cout << obj->shouldPrintMessage(2, "bar") << endl;
    cout << obj->shouldPrintMessage(3, "foo") << endl;
    cout << obj->shouldPrintMessage(8, "bar") << endl;
    cout << obj->shouldPrintMessage(10, "foo") << endl;
    cout << obj->shouldPrintMessage(11, "foo") << endl;
    return 0;
}
