#include <queue>
using namespace std;

class MovingAverage {
    queue<int> q;
    int capacity;
    double sum;
public:
    MovingAverage(int size) : capacity(size) {}
    
    double next(int val) {
        if (q.size() == capacity) {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;

        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */