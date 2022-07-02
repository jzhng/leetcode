#include <iostream>
#include <ctime>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> indices;
public:
    RandomizedSet() {
        srand((unsigned) time(nullptr));
    }
    
    bool insert(int val) {
        if (indices.count(val)) {
            return false;
        }
        nums.emplace_back(val);
        indices[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!indices.count(val)) {
            return false;
        }
        int idx = indices[val];
        nums[idx] = nums.back();
        nums.pop_back();
        indices[nums[idx]] = idx;
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedSet* obj = new RandomizedSet();
    cout << obj->insert(0) << endl;
    cout << obj->insert(1) << endl;
    cout << obj->remove(0) << endl;
    cout << obj->insert(2) << endl;
    cout << obj->remove(1) << endl;
    cout << obj->getRandom() << endl;
    return 0;
}