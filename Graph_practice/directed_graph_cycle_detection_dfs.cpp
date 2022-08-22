#include<iostream>
#include<vector>
using namespace std;

// Time complexity : O(V + E)
// Space complexity : O(V + E) + O(2V) + O(V)

bool dfsCycCheck(int node, vector<int> adj[], vector<bool>& visit, vector<bool>& dfsVis) {
	
	visit[node] = dfsVis[node] = true;

	for (int neigh : adj[node]) {
		if (!visit[neigh]) {
			if (dfsCycCheck(neigh, adj, visit, dfsVis)) {
				return true;
			}
		}
		else if (dfsVis[neigh]) {
			return true;
		}
	}

	dfsVis[node] = false;

	return false;
}

bool checkCycle(vector<int> adj[], int N) {
	vector<bool> visit(N + 1, false);
	vector<bool> dfsVis(N + 1, false);

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			if (dfsCycCheck(i, adj, visit, dfsVis)) {
				return true;
			}
		}
	}

	return false;
}	

int main() {
	int N = 9;
	vector<int> adj[N + 1];

	adj[1].push_back(2);

	adj[2].push_back(3);

	adj[3].push_back(4);
	adj[3].push_back(6);

	adj[4].push_back(5);
	
	adj[6].push_back(5);

	adj[7].push_back(2);
	adj[7].push_back(8);

	adj[8].push_back(9);

	adj[9].push_back(7);

	if (checkCycle(adj, N)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}