class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0;
        while (x || y) {
            int b1 = x % 2;
            int b2 = y % 2;
            if (b1 != b2) dist++;
            x /= 2;
            y /= 2;
        }
        return dist;
    }
};