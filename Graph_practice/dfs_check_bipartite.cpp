#include<iostream>
#include<vector>

using namespace std;

/*
	Works only when an even cycle or no cylce is present. 
	Not possible for odd-length cycles.
*/
// Time complexity: O(V + E)

// Space complexity: O(V + E) + O(V) + Auxiliary Stack Space of O(V)

bool dfsCheckBip(int src, vector<int> adj[], vector<int>& color, int currCol) {
	color[src] = currCol;

	for (int neigh : adj[src]) {
		if (color[neigh] == -1) {
			if (!dfsCheckBip(neigh, adj, color, 1 - currCol)) {
				return false;
			}
		}
		else {
			if (color[neigh] == currCol) {
				return false;
			}
		}
	}
	return true;
}

bool checkBip(vector<int> adj[], int N) {
	vector<int> color(N, -1);

	for (int i = 1; i <= N; i++) {
		if (color[i] == -1) {
			if (!dfsCheckBip(i, adj, color, 0)) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	int N = 6;
	vector<int> adj[N + 1];

	// Declare graph
	adj[1].push_back(2);
	
	adj[2].push_back(1);
	adj[2].push_back(3);
	

	adj[3].push_back(2);
	adj[3].push_back(4);

	adj[4].push_back(3);
	adj[4].push_back(5);

	adj[5].push_back(2);
	adj[5].push_back(4);
	adj[5].push_back(6);
	
	adj[6].push_back(5);

	if (checkBip(adj, N + 1)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}