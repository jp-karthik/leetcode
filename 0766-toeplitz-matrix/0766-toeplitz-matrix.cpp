class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool b = true;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            pair<int, int> start = {i, 0};
            int cx = start.first + 1;
            int cy = start.second + 1;
            while (cx < n && cy < m) {
                if (matrix[cx][cy] != matrix[cx - 1][cy - 1]) {
                    b = false;
                }
                cx++;
                cy++;
            }
        }
        for (int i = 0; i < m; i++) {
            pair<int, int> start = {0, i};
            int cx = start.first + 1;
            int cy = start.second + 1;
            while (cx < n && cy < m) {
                if (matrix[cx][cy] != matrix[cx - 1][cy - 1]) {
                    b = false;
                }
                cx++;
                cy++;
            }
        }
        return b;
    }
};