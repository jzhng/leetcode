#include <iostream>
#include <vector>
#include <list>
using namespace std;

class MyHashMap {
    static const int capacity = 911;
    vector<list<pair<int, int>>> data;
public:
    MyHashMap() : data(capacity) {}
    
    void put(int key, int value) {
        int h = key % capacity;
        auto &li = data[h];
        for (auto it = li.begin(); it != li.end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }

        li.push_back({key, value});
    }
    
    int get(int key) {
        int h = key % capacity;
        auto &li = data[h];
        for (auto it = li.begin(); it != li.end(); ++it) {
            if (it->first == key) return it->second;
        }
        return -1;
    }
    
    void remove(int key) {
        int h = key % capacity;
        auto &li = data[h];
        for (auto it = li.begin(); it != li.end(); ++it) {
            if (it->first == key) {
                li.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    MyHashMap s;
    s.put(1, 1);
    s.put(2, 2);
    cout << s.get(1) << endl;
    cout << s.get(3) << endl;
    s.put(2, 1);
    cout << s.get(2) << endl;
    s.remove(2);
    cout << s.get(2) << endl;
    return 0;
}
