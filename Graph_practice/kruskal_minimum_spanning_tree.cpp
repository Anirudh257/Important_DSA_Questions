#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

/* 
	Time complexity:
		Sorting edges: O(mlogm)
		Graph creation: O(n)
		Check if same component: O(m)*O(alpa(n))
		
		Overall O(mlogm)

	Space complexity:
		adj: O(m + n)
		edges: O(m) 
		rank: O(n)
		root: O(n)
		
		m edges, n nodes
*/
class UnionFind {
public:
	UnionFind(int sz) : root(sz), rank(sz) {
		for (int i = 0; i < sz; i++) {
			root[i] = i;
			rank[i] = 1;
		}
	}

	int findPar(int x) {
		if (x == root[x]) {
			return x;
		}
		return root[x] = findPar(root[x]);
	}

	void unionSet(int u, int v) {
		int rootU = findPar(u);
		int rootV = findPar(v);

		if (rootU != rootV) {
			if (rank[rootU] > rank[rootV]) {
				root[rootV] = rootU;
			}
			else if (rank[rootU] < rank[rootV]) {
				root[rootU] = rootV;
			}
			else {
				root[rootV] = rootU;
				rank[rootU]++;
			}
		}
	}

	bool isSameComp(int x, int y) {
		return root[x] == root[y];
	}

private:
	vector<int> root;
	vector<int> rank;
};

int main() {
	int N = 6;
	vector<pair<int, int>> adj[N + 1];

	adj[1].push_back(make_pair(2, 2));
	adj[1].push_back(make_pair(4, 1));
	adj[1].push_back(make_pair(5, 4));

	adj[2].push_back(make_pair(3, 3));
	adj[2].push_back(make_pair(4, 3));
	adj[2].push_back(make_pair(6, 7));

	adj[3].push_back(make_pair(4, 5));
	adj[3].push_back(make_pair(6, 8));

	adj[4].push_back(make_pair(5, 9));

	vector<vector<int>> edges;
	for (int i = 1; i <= N; i++) {
		for (auto &edge : adj[i]) {
			vector<int> temp = {edge.second, i, edge.first};
			edges.push_back(temp); 
		}
	}

	// weight, src, dest
	sort(edges.begin(), edges.end(), cmp);

	vector<vector<int>> minSpanTree;
		
	UnionFind uf(N + 1);

	for (auto &edge : edges) {
		int wt = edge[0];
		int src = edge[1];
		int dest = edge[2];

		if (uf.isSameComp(src, dest)) {
			continue;
		}
		else {
			uf.unionSet(src, dest);
			minSpanTree.push_back(edge);
		}
	}

	for (auto &x: minSpanTree) {
		cout << "Weight: " << x[0] << " Source: " << x[1] << " Destination: " << x[2] << endl;
	}


	return 0;
}