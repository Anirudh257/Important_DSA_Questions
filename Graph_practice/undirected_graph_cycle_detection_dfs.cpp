#include<iostream>
#include<stdio.h>
#include <vector>

using namespace std;

// Time complexity: O(N + E)
// Space complexity: O(N + E) + O(N) + Aux Space of O(N)

class Solution {
public:
	bool isCycle(int n, vector<int> adjList[]) {
		visited.resize(n + 1, false);

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				if (checkForCycle(i, -1, n, adjList)) {
					return true;
				}
			}
		}
		return false;
	}

private:
	vector<bool> visited;
	bool checkForCycle(int node, int par, int n, vector<int> adjList[]) {
		visited[node] = true;
		
		for (auto neigh : adjList[node]) {
			if (!visited[neigh]) {
				if (checkForCycle(neigh, node, n, adjList)) {
					return true;
				}
			}
			else if (neigh != par) {
				return true;
			}
		}

		return false;
	}
};

void addEdge(vector<int> adjList[], int src, int dest) {
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}

int main() {
	int n = 6;
	vector<int> adjList[n + 1];

	addEdge(adjList, 1, 2);
	addEdge(adjList, 2, 4);
	addEdge(adjList, 3, 5);
	addEdge(adjList, 3, 6);
	// addEdge(adjList, 5, 6);
	// addEdge(adjList, 5, 10);
	// addEdge(adjList, 6, 7);
	// // addEdge(adjList, 7, 8);
	// addEdge(adjList, 8, 9);
	// addEdge(adjList, 8, 11);
	// addEdge(adjList, 9, 10);

	Solution obj;

	bool ans = obj.isCycle(n, adjList);

	cout << ans << endl;

	return 0;
}