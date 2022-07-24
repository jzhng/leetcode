#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hashmap;
        for (int i = 0; i < list1.size(); ++i) {
            hashmap[list1[i]] = i;
        }

        int min = INT_MAX;
        vector<string> res;
        for (int i = 0; i < list2.size(); ++i) {
            if (hashmap.count(list2[i])) {
                int sum = hashmap[list2[i]] + i;
                if (sum < min) {
                    min = sum;
                    res.clear();
                    res.push_back(list2[i]);
                } else if (sum == min) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};
