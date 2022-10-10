class Solution {
public:
    int n, m;
    int gx, gy;
    int sx, sy;
    
    int validCells = 0;
    int visitedCells = 0;
    
    vector<vector<bool>> vis;
    vector<vector<int>> g;
    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool validate(int x, int y) {
        // bound validation
        if (x < 0 || x >= n) {
            return false;
        }
        if (y < 0 || y >= m) {
            return false;
        }
        
        // obstacle validation
        if (g[x][y] == -1) {
            return false;
        }
        
        // visited validation
        if (vis[x][y]) {
            return false;
        } else return true;
    }
    
    int dfs(int x, int y) {    
        vis[x][y] = true;
        visitedCells++;
    
        // goal is reached
        if (gx == x && gy == y) {
            if (visitedCells == validCells) {
                vis[x][y] = false;
                visitedCells--;
                return 1;
            } else {
                vis[x][y] = false;
                visitedCells--;
                return 0;
            }
        }
    
        int res = 0;    
        for (auto m : moves) {
            int nx = x + m[0];
            int ny = y + m[1];
            if (validate(nx, ny)) {
                res += dfs(nx, ny);
            }
        }
        vis[x][y] = false;
        visitedCells--;
        
        return res;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (grid[i][j] != -1) {
                    validCells++;
                }
                
                if (grid[i][j] == 2) {
                    gx = i;
                    gy = j;
                }
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }
        
        vis.resize(n, vector<bool>(m, false));
        g = grid;
        
        return dfs(sx, sy);
    }
};