class Solution {
public:
    vector<vector<int>> g;
    vector<bool> vis;
    
    int dfs(int u) {
        vis[u] = true;
        int curr = 0;
        for (int v : g[u]) {
            if (!vis[v]) {
                curr += dfs(v);
            }
        }
        return curr + 1;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        // nodes : 0 to n - 1
        g.resize(n, {});
        vis.resize(n, false);
        
        // creating graph
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                bool b = stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1];
                if (b) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                res += dfs(i) - 1;
            }
        }
        
        return res;
    }
};