#include<iostream>
#include<stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	bool isCycle(int n, vector<int> adjList[]) {
		vector<bool> visited(n + 1, false);

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				if (checkForCycle(i, n, adjList, visited)) {
					return true;
				}
			}
		}
		return false;
	}

private:
	bool checkForCycle(int node, int n, vector<int> adjList[], vector<bool>& visited) {
		visited[node] = true;
		queue<pair<int, int>> q;
		q.push({node, -1});

		while(!q.empty()) {
			int node = q.front().first;
			int par = q.front().second;
			q.pop();

			for (auto neigh : adjList[node]) {
				if (!visited[neigh]) {
					visited[neigh] = true;
					q.push({neigh, node});
				}
				else if (par != neigh){
					return true;
				}
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
	int n = 11;
	vector<int> adjList[n + 1];

	addEdge(adjList, 1, 2);
	addEdge(adjList, 2, 4);
	addEdge(adjList, 3, 5);
	addEdge(adjList, 5, 6);
	addEdge(adjList, 5, 10);
	addEdge(adjList, 6, 7);
	addEdge(adjList, 7, 8);
	addEdge(adjList, 8, 9);
	addEdge(adjList, 8, 11);
	addEdge(adjList, 9, 10);

	Solution obj;

	bool ans = obj.isCycle(n, adjList);

	cout << ans << endl;

	return 0;
}