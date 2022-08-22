#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Time complexity: O(V + E)
// Space complexity: O(V + E) + O(V) + O(V)

/*
	Works only when an even cycle or no cylce is present. 
	Not possible for odd-length cycles.
*/

bool bipartiteBFS(int node, vector<int> adj[], vector<int>& color) {

	queue<int> q;
	q.push(node);
	color[node] = 0;

	while(!q.empty()) {
		int top = q.front();
		q.pop();

		int col = color[top];

		for (int neigh : adj[top]) {
			if (color[neigh] != -1) {
				int neighCol = color[neigh];
				if (neighCol == col) {
					return false;
				}
			}
			else {
				if (col == 0) {
					color[neigh] = 1;
				}
				else {
					color[neigh] = 0;
				}
				q.push(neigh);
			}
		}
	}
	return true;
}



bool checkBip(vector<int> adj[], int N) {
	vector<int> color(N + 1, -1);

	for (int i = 1; i <= N; i++) {
		if (color[i] == -1) {
			if (!bipartiteBFS(i, adj, color)) {
				return false;
			}
		}
	}
	return true;
}


int main() {
	int N = 8;
	vector<int> adj[N + 1];

	// Declare graph
	adj[1].push_back(2);
	
	adj[2].push_back(1);
	adj[2].push_back(3);
	adj[2].push_back(7);

	adj[3].push_back(2);
	adj[3].push_back(4);

	adj[4].push_back(3);
	adj[4].push_back(5);

	adj[5].push_back(4);
	adj[5].push_back(6);
	adj[5].push_back(8);

	adj[6].push_back(5);
	adj[6].push_back(7);

	adj[7].push_back(2);
	adj[7].push_back(6);

	adj[8].push_back(5);

	if (checkBip(adj, N)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}