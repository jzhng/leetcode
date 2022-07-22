#include <vector>
#include <queue>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
public:
    KthLargest(int k, vector<int>& nums) : size(k), pq(nums.begin(), nums.end()){
        while (pq.size() > size) pq.pop();
    }
    
    int add(int val) {
        if (pq.size() < size) {
            pq.push(val);
        } else {
            if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */