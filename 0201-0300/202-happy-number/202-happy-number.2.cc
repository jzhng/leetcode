class Solution {
    int getNext(int n) {
        int sum = 0;
        while (n) {
            int t = n % 10;
            sum += t * t;
            n = n / 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = getNext(n);
        int fast = getNext(slow);

        while (slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return slow == 1;
    }
};
