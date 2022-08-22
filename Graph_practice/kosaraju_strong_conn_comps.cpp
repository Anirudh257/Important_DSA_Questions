#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
	Time complexity: O(N + E) for topological sorting, O(N + E) for transposing edges
		O(N + E) for Kosaraju's DFS
	
	Space complexity: O(N) for topological sorting, O(N + E) for transposed graph,
	O(N) for Kosaraju's DFS

*/


void dfs(vector<int> adj[], int node, vector<bool>& visited, stack<int>& st) {
	visited[node] = true;


	for (int neigh : adj[node]) {
		if (!visited[neigh]) {
			dfs(adj, neigh, visited, st);
		}
	}
	// cout << node << endl;

	st.push(node);
}

stack<int> topoSort(vector<int> adj[], int n) {
	vector<bool>visited(n, false);

	stack<int> st;

	for (int i = 1; i < n; i++) {
		if (!visited[i]) {
			dfs(adj, i, visited, st);
			// st.push(node);
		}
	}
	return st;
}

void kosarajuDFS(int node, vector<int>& strongComp, vector<int> adj[], 
	vector<bool>& visited) {
		visited[node] = true;
		strongComp.push_back(node);

		for (int neigh : adj[node]) {
			if (!visited[neigh]) {
				kosarajuDFS(neigh, strongComp, adj, visited);
			}
		}
}


int main() {
	int n = 5;
	vector<int> adj[n + 1];

	adj[1].push_back(2);

	adj[2].push_back(3);
	adj[2].push_back(4);

	adj[3].push_back(1);

	adj[4].push_back(5);

	stack<int> topSt = topoSort(adj, n + 1);

	vector<int> transp[n + 1];

	for (int i = 1; i <= n; i++) {
		for (int neigh : adj[i]) {
			transp[neigh].push_back(i);
		}
	}

	vector<vector<int>> strongComps;

	vector<bool> visited(n + 1, false);

	while(!topSt.empty()) {
		int top = topSt.top();
		topSt.pop();
		if (!visited[top]) {
			vector<int> row;
			kosarajuDFS(top, row, transp, visited);
			strongComps.push_back(row);
		}
	}

	for (auto &comp : strongComps) {
		for (auto &x : comp) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}