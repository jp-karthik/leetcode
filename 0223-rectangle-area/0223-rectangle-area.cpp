class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int l1 = ax2 - ax1;
        int b1 = ay2 - ay1;
        int l2 = bx2 - bx1;
        int b2 = by2 - by1;
        int res = l1 * b1 + l2 * b2;
        bool cnd = by2 <= ay1 || by1 >= ay2 || bx1 >= ax2 || bx2 <= ax1;
        if (cnd) {
            return res;
        } else {
            int cx2 = min(ax2, bx2);
            int cy2 = min(ay2, by2);
            int cx1 = max(ax1, bx1);
            int cy1 = max(ay1, by1);
            int over = (cx2 - cx1) * (cy2 - cy1);
            return res - over;
        }
    }
};