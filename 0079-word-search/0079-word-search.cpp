class Solution {
public:
    vector<vector<char>> b;
    int n, m, len;
    string s;
    
    vector<vector<bool>> vis;
   
    bool dfs(int x, int y, int i) {
        if (i == len) return true;
        if (x < 0 || x >= n || y < 0 || y >= m) return false;
        if (vis[x][y]) return false;
        if (b[x][y] != s[i]) return false;
        
        bool res = false;
        vis[x][y] = true;
        res = res || dfs(x + 1, y, i + 1);
        res = res || dfs(x - 1, y, i + 1);
        res = res || dfs(x, y - 1, i + 1);
        res = res || dfs(x, y + 1, i + 1);
        vis[x][y] = false;
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        b = board;
        s = word;

        n = b.size();
        m = b[0].size();
        len = s.length();
        
        vis.resize(n, vector<bool>(m, false));
        
        bool res = false;
        
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (b[x][y] == word[0]) {
                    res = res || dfs(x, y, 0);
                    if (res) return true;
                }
            }
        }
        
        return res;
    }
};