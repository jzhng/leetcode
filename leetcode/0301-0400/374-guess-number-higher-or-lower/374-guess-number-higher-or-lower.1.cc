/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int i = 1, j = n;
        while (i <= j) {
            int target = i + (j - i) / 2;
            int res = guess(target);
            if (res == 0) {
                return target;
            } else if (res == -1) {
                j = target - 1;
            } else {
                i = target + 1;
            }
        }
        return -1;
    }
};