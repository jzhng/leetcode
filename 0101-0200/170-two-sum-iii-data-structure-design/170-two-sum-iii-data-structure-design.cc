#include <unordered_map>
using namespace std;

class TwoSum {
    unordered_map<int, int> nums;

public:
    TwoSum() {}
    
    void add(int number) {
        ++nums[number];
    }
    
    bool find(int value) {
        if (value > 200000 || value < -20000) {
            return false;
        }

        for (auto [k1, v1] : nums) {
            int k2 = value - k1;
            if (k1 == k2) {
                if (v1 > 1) return true;
            } else {
                if (nums.count(k2)) return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */