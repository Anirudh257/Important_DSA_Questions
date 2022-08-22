#include<iostream>
#include<utility>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

// Time complexity: O(n*logn + n + e)), Space complexity: O(n + m)  + 3(O(n)), n = number of nodes
// m = number of edges

vector<int> primMST(vector<pair<int, int>> adj [], int n) {
	vector<int> key(n, INT_MAX);
	vector<bool> mst(n, false);
	vector<int> parent(n, -1);

	key[1] = 0;
	parent[1] = -1;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

	pq.push({0, 1});

	for (int count = 0; count < n - 1; count++) {
		int minKey = pq.top().second;
		mst[minKey] = true;

		pq.pop();

		for (auto &neigh : adj[minKey]) {
			int node = neigh.first;
			int weight = neigh.second;

			if (!mst[node] && weight < key[node]) {
				parent[node] = minKey;
				key[node] = weight;
				pq.push(make_pair(weight, node));
			}
		}
	}

	return parent;
}

int main() {
	int n = 6;
	vector<pair<int, int>> adj[n + 1];

	adj[1].push_back(make_pair(2, 2));
	adj[1].push_back(make_pair(4, 1));
	adj[1].push_back(make_pair(5, 4));

	adj[2].push_back(make_pair(3, 3));
	adj[2].push_back(make_pair(4, 3));
	adj[2].push_back(make_pair(6, 7));

	adj[3].push_back(make_pair(4, 5));
	adj[3].push_back(make_pair(6, 8));

	adj[4].push_back(make_pair(5, 9));


	// for (int i = 1; i <= n; i++) {
	// 	for (auto &x : adj[i]) {
	// 		cout << "Path of edge from src: " << i << " to " << "dest: " << x.first << " is weight " << x.second << endl;
	// 	}
	// }

	vector<int> mst = primMST(adj, n + 1);

	for (auto &x : mst) {
		cout << x << endl;
	}

	return 0;
}