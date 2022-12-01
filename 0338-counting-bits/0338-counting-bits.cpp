class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n + 1);
        for (int i = 0; i <= n; i++) {
            int x = 0;
            int temp = i;
            while (temp) {
                x += temp % 2;
                temp /= 2;
            }
            v[i] = x;
        }
        return v;
    }
};