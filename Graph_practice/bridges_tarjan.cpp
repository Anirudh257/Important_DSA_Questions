#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Time complexity: O(V + E): V = #vertices, E = #edges = same as DFS time.
// Space complexity: O(V + E) + O(3V)

void dfs(vector<pair<int, int>>& bridges, int currNode, vector<int>& disc, vector<int>& low,
	vector<int>& parent, vector<int> adj[]) {
	static int time = 0;
	disc[currNode] = low[currNode] = time;
	time++;

	for (int neigh : adj[currNode]) {
		if (disc[neigh] == -1) {
			parent[neigh] = currNode;
			dfs(bridges, neigh, disc, low, parent, adj);

			low[currNode] = min(low[currNode], low[neigh]);

			if (low[neigh] > low[currNode]) {
				bridges.push_back({currNode, neigh});
			}

		}
		else {
			if (neigh != parent[currNode]) {
				low[currNode] = min(low[currNode], disc[neigh]);
			}
		}
	}

}

vector<pair<int, int>> findBridges(vector<int> adj[], int n) {
	vector<int> disc(n, -1), low(n, -1), parent(n, -1);
	vector<pair<int, int>> bridges;

	for (int i = 1; i < n; i++) {
		if (disc[i] == -1) {
			dfs(bridges, i, disc, low, parent, adj);
		}
	}

	return bridges;
}

int main() {
	int N = 12;
	vector<int> adj[N + 1];

	adj[1].push_back(2);
	adj[1].push_back(4);

	adj[2].push_back(1);
	adj[2].push_back(3);

	adj[3].push_back(2);
	adj[3].push_back(4);

	adj[4].push_back(1);
	adj[4].push_back(5);

	adj[5].push_back(4);
	adj[5].push_back(6);

	adj[6].push_back(5);
	adj[6].push_back(7);
	adj[6].push_back(9);

	adj[7].push_back(6);
	adj[7].push_back(8);

	adj[8].push_back(7);
	adj[8].push_back(9);
	adj[8].push_back(10);

	adj[9].push_back(6);
	adj[9].push_back(8);

	adj[10].push_back(8);
	adj[10].push_back(11);
	adj[10].push_back(12);

	adj[11].push_back(10);
	adj[11].push_back(12);

	adj[12].push_back(10);
	adj[12].push_back(11);

	vector<pair<int, int>> bridges = findBridges(adj, N + 1);

	for (auto &x : bridges) {
		cout << x.first << " " << x.second << endl;
	}

	return 0;
}