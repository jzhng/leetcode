class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, min = INT_MAX;
        int n = gas.size(), idx = -1;

        for (int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            if (min > sum) {
                min = sum;
                idx = i;
            }
        }

        if (sum < 0) return -1;
        return (idx + 1) % n;
    }
};
