
class binaryLifting {
private:
	vector<vector<long long>> up;
	vector<long long> depth;
	vector<vector<long long>> g;
	int LOG = 0;
public:
	binaryLifting(vector<long long>& parent) {
		TreeAncestor(parent);
		depth.resize(parent.size());
		g.resize(parent.size());
		for (int i = 1; i < parent.size(); i++) {
			g[i].push_back(parent[i]);
			g[parent[i]].push_back(i);
		}
		DFS(0, -1);
	}
	void TreeAncestor(vector<long long>& parent) {
		int n = parent.size();
		int tmp = n;
		while (tmp) {
			tmp /= 2;
			LOG++;
		}
		up.resize(n, vector<long long>(LOG + 1));
		for (int i = 0; i < n; i++) {
			up[i][0] = parent[i];
		}
		for (int j = 1; j <= LOG; j++) {
			for (int i = 0; i < n; i++) {
				up[i][j] = up[up[i][j - 1]][j - 1];  
			}
		}
	}
	void DFS(int u, int p) {
		if (p == -1) {
			depth[u] = 0;
		}
		for (auto v : g[u]) {
			if (v != p) {
				depth[v] = depth[u] + 1;
				DFS(v, u);
			}
		} 
	}
	int get(int node, int k) {
		if (depth[node] < k) {
			return -1;
		} else {
			for (int i = LOG; i >= 0; i--) {
				int val = (1 << i);
				if (k & val) {
					node = up[node][i];
					k -= val;
				}
			}
			return node;
		}
	}
};

binaryLifting* tree;
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        vector<long long> modPar(n);
        for (int i = 0; i < n; i++) {
            modPar[i] = parent[i];
        }
        modPar[0] = 0;
        tree = new binaryLifting(modPar);
    }
    
    int getKthAncestor(int node, int k) {
        return tree->get(node, k);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */