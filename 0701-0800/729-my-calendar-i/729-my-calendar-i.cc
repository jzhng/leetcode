#include <vector>
using namespace std;

class MyCalendar {
    vector<pair<int, int>> booked;
    bool check(pair<int, int> x, pair<int, int> y) {
        return (y.second <= x.first || x.second <= y.first);
              
    }
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        bool intersect = false;
        auto toBook = make_pair(start, end);
        for (auto interval: booked) {
            if (!check(interval, toBook)) {
                intersect = true;
                break;
            }
        }

        if (!intersect) booked.push_back(toBook);
        return !intersect;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */