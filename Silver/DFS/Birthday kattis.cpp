#include<bits/stdc++.h>
using namespace std;

int n, m;
// Adjacency matrix
bool adj[105][105];
bool vis[105];

void dfs(int v) {
	vis[v] = true;
	for (int to = 0; to < n; to++) {
		if (adj[v][to] && !vis[to]) {
			dfs(to);
		}
	}
}

void solve() {
	memset(adj, false, sizeof(adj));
	vector<pair<int,int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = true;
		adj[v][u] = true;
		edges.push_back({u, v});
	}
	for (auto x : edges) {
		adj[x.first][x.second] = false;
		adj[x.second][x.first] = false;
		memset(vis, false, sizeof(vis));
		dfs(0);
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				cout << "Yes" << '\n';
				return;
			}
		}
		adj[x.first][x.second] = true;
		adj[x.second][x.first] = true;
	}
	cout << "No" << '\n';
}

int main() {
	while (cin >> n >> m && (n || m)) {
		solve();
	}
}