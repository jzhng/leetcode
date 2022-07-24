#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
    vector<int> q;
    int size;
    int front = 0;
    int rear = 0;
public:
    MyCircularQueue(int k): size(k+1), front(0), rear(0) {
        q.resize(k+1);
    }
    
    bool enQueue(int value) {
        if (!isFull()) {
            q[rear] = value;
            rear = (rear+1) % size;
            return true;
        }
        return false;
    }

    bool deQueue() {
        if (!isEmpty()) {
            front = (front+1) % size;
            return true;
        }
        return false;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        } else {
            return q[front];
        }
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        } else {
            return q[(rear - 1 + size) % size];
        }
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear + 1) % size == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
    MyCircularQueue* obj = new MyCircularQueue(3);
    cout << obj->enQueue(1) << endl;
    cout << obj->enQueue(2) << endl;
    cout << obj->enQueue(3) << endl;
    cout << obj->enQueue(4) << endl;
    cout << "Front: " << obj->Front() << endl;
    cout << obj->Rear() << endl;
    cout << obj->isEmpty() << endl;
    cout << obj->isFull() << endl;
    cout << obj->deQueue() << endl;
    cout << "Front: " << obj->Front() << endl;

    return 0;
}