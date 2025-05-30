#include <iostream>
#include <vector>
#include <list>
using namespace std;

class MyHashSet {
    static const int size = 911;
    vector<list<int>> data;
public:
    MyHashSet(): data(size) {}
    
    void add(int key) {
        int h = key % size;
        auto &li = data[h];
        for (auto it = li.begin(); it != li.end(); ++it) {
            if (*it == key) return;
        }
        li.push_back(key);
    }
    
    void remove(int key) {
        int h = key % size;
        auto &li = data[h];
        for (auto it = li.begin(); it != li.end(); ++it) {
            if (*it == key) {
                li.erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int h = key % size;
        auto &li = data[h];
        for (auto it = li.begin(); it != li.end(); ++it) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {
    MyHashSet s;
    s.add(1);
    s.add(2);
    cout << s.contains(1) << endl;
    cout << s.contains(3) << endl;
    s.add(2);
    cout << s.contains(2) << endl;
    s.remove(2);
    cout << s.contains(2) << endl;
    return 0;
}
