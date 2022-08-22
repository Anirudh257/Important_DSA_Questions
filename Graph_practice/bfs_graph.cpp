#include<stdio.h>
#include<iostream>
#include<vector>
#include <queue>

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
int n = 7;
vector<int> bfsTrav;
vector<bool> visited(n, false);

void bfsHelper(int node, vector<int> adjList[]) {	
	queue<int> q;

	q.push(node);

	// cout << node << endl;
	while(!q.empty()) {
		int top = q.front();
		q.pop();
		bfsTrav.push_back(top);
		visited[top] = true;

		for (int neigh : adjList[node]) {
			if (!visited[neigh]) {
				q.push(neigh);
			}
		}
	}
}

void bfs(int n, vector<int> adjList[]) {
	

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfsHelper(i, adjList);
		}
	}
}

int main() {

	// Generate graph
	int n = 7;
	vector<int> adjList[n + 1];

	adjList[1].push_back(2);
	adjList[2].push_back(1);

	adjList[2].push_back(3);
	adjList[3].push_back(2);

	adjList[2].push_back(7);
	adjList[7].push_back(2);

	adjList[3].push_back(5);
	adjList[5].push_back(3);

	adjList[5].push_back(7);
	adjList[7].push_back(5);

	adjList[4].push_back(6);
	adjList[6].push_back(4);

	// printGraph(n, adjList);

	bfs(n, adjList);

	for (auto &x : bfsTrav) {
		cout << x << endl;
	}

	return 0;
}