class Solution {
public:
    int m, n;
    
    vector<vector<bool>> vis;
    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<char>> g;
    
    bool isValid(int x, int y) {
        if (x < 0 || x >= m) return false;
        if (y < 0 || y >= n) return false;
        if (g[x][y] == '0') return false;
        if (vis[x][y]) return false;
        else return true;
    }
    void dfs(int x, int y) {
        vis[x][y] = true;
        for (auto m : moves) {
            int nx = x + m[0];
            int ny = y + m[1];
            if (isValid(nx, ny)) {
                dfs(nx, ny);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        g = grid;
        vis.resize(m, vector<bool>(n, false));
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};