#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<int> data;
    int min = INT_MAX;
public:
    MinStack() {}
    
    void push(int val) {
        if (val <= min) {
            data.push(min);
            min = val;
        }
        data.push(val);
    }
    
    void pop() {
        if (min == data.top()) {
            data.pop();
            min = data.top();
            data.pop();
        } else {
            data.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    return 0;
}
