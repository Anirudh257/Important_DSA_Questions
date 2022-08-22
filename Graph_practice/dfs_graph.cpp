#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

void printGraph(int n, vector<int> adjList[]) {
	for (int i = 1; i <= n; i++) {
		cout << i << " -> ";
		for (auto n : adjList[i]) {
			cout << n << " ";
		}
		cout << endl;
	}
}

void dfs(int node, vector<bool>& visited, vector<int> adjList[], vector<int>& dfsTrav) {
	visited[node] = true;
	dfsTrav.push_back(node);

	for (auto neigh : adjList[node]) {
		if (!visited[neigh]) {
			dfs(neigh, visited, adjList, dfsTrav);
		}
	}

}

int main() {

	// Generate graph
	int n = 7;
	vector<int> adjList[n + 1];

	adjList[1].push_back(2);
	adjList[2].push_back(1);

	adjList[2].push_back(4);
	adjList[4].push_back(2);

	adjList[2].push_back(7);
	adjList[7].push_back(2);

	adjList[3].push_back(5);
	adjList[5].push_back(3);

	adjList[4].push_back(6);
	adjList[6].push_back(4);

	adjList[6].push_back(7);
	adjList[7].push_back(6);

	// printGraph(n, adjList);
	vector<bool>visited(n + 1, false);
	vector<int> dfsTrav;

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, visited, adjList, dfsTrav);
		}
	}

	for (auto &x : dfsTrav) {
		cout << x << endl;
	}



	return 0;
}