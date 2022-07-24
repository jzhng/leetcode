#include <vector>
using namespace std;

class Solution {
public:
    int numPrimeArrangements(int n) {
        vector<bool> primes(n+1, true);
        primes[1] = false;

        for (int i = 2; i * i <= n; ++i) {
            if (primes[i]) {
                for (int j = 2 * i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (primes[i]) ++cnt;
        }

        long res = 1;
        for (int i = 1; i <= cnt; ++i) {
            res = (res * i) % 1000000007;
        }

        for (int i = 1; i <= n - cnt; ++i) {
            res = (res * i) % 1000000007;
        }

        return static_cast<int>(res);
    }
};
