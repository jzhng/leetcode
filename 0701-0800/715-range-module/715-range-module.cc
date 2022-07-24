#include <iostream>
#include <map>
#include <iterator>
using namespace std;

class RangeModule {
    map<int, int> ranges;

public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        auto it = ranges.upper_bound(left);
        if (it != ranges.begin()) {
            auto start = prev(it);
            if (start->second >= right) {
                return;
            }
            if (start->second >= left) {
                left = start->first;
                ranges.erase(start);
            }
        }
        while (it != ranges.end() && it->first <= right) {
            right = max(right, it->second);
            it = ranges.erase(it);
        }
        ranges[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = ranges.upper_bound(left);
        if (it == ranges.begin()) return false;
        it = prev(it);
        return right <= it->second;
    }
    
    void removeRange(int left, int right) {
        auto it = ranges.upper_bound(left);
        if (it != ranges.begin()) {
            auto start = prev(it);
            if (start->second >= right) {
                int ri = start->second;
                if (start->first == left) {
                    ranges.erase(start);
                }
                else {
                    start->second = left;
                }
                if (right != ri) {
                    ranges[right] = ri;
                }
                return;
            }
            else if (start->second > left) {
                start->second = left;
            }
        }
        while (it != ranges.end() && it->first < right) {
            if (it->second <= right) {
                it = ranges.erase(it);
            }
            else {
                ranges[right] = it->second;
                ranges.erase(it);
                break;
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

int main() {
    RangeModule* obj = new RangeModule();
    obj->addRange(10, 20);
    obj->removeRange(14, 16);
    cout << obj->queryRange(10, 14) << endl;
    cout << obj->queryRange(13, 15) << endl;
    cout << obj->queryRange(16, 17) << endl;
    return 0;
}