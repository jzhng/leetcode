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
        int l = 1, r = n;
        while (l < r) {
            int pick = l + (r - l) / 2;
            if (guess(pick) <= 0) {
                r = pick;
            } else {
                l = pick + 1;
            }
        }
        return l;
    }
};