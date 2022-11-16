/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long low = 1;
        long long high = n;
        long long result = -1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            int cmp = guess(mid);
            if (cmp == 0) {
                result = mid;
                break;
            } else if (cmp == -1) {
                high = mid - 1;
            } else if (cmp == 1) {
                low = mid + 1;
            }
        }
        return result;
    }
};