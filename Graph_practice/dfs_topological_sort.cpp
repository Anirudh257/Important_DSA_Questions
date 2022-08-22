#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Time complexity : O(V + E), Space complexity: O(V + E) + O(V) + O(V) + 
// auxiliary space of O(V)

// Only works for Directed Acyclic Graphs.
// Not working if cycles present or undirected graphs.

class Solution {
private:
	void perfTopDFS(int node, vector<int> adj[], int N, vector<bool>& visited, 
		stack<int>& topSort) {
		
		visited[node] = true;

		int reqNode = node;

		for (int neigh : adj[node]) {
			if (!visited[neigh]) {
				perfTopDFS(neigh, adj, N, visited, topSort);
			}
		}

		topSort.push(reqNode);
	}

public:
	vector<int> compDfs(vector<int> adj[], int N) {

		vector<bool> visited;
		visited.resize(N, false);
		stack<int> topSort;

		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				perfTopDFS(i, adj, N, visited, topSort);
			}
		}

		vector<int> topOrder;

		while(!topSort.empty()) {
			int top = topSort.top();
			topOrder.push_back(top);
			topSort.pop();
		}

		return topOrder;
	}
};

int main() {
	int N = 6;
	vector<int> adj[N];

	adj[2].push_back(3);

	adj[3].push_back(1);
	
	adj[4].push_back(0);
	adj[4].push_back(1);
	
	adj[5].push_back(0);
	adj[5].push_back(2);

	Solution obj;

	vector<int> dfsTop = obj.compDfs(adj, N);

	for (auto &x : dfsTop) {
		cout << x << endl;
	}

	return 0;
}