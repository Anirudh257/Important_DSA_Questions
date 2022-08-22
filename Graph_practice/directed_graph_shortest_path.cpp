#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<utility>

using namespace std;

// Time complexity: O(V + E) [Topological Sort] + O(V + E) [BFS] 
// Space complexity: O(V + E) [Adjacency list] + O(V) + O(V) + Auxiliary space of DFS(O(V))

stack<int> dfs(int node, vector<bool>& visited, vector<pair<int, int>> adjList[], stack<int>& topOrder) {
	visited[node] = true;

	for (auto it : adjList[node]) {
		if (!visited[it.first]) {
			dfs(it.first, visited, adjList, topOrder);
		}
	}

	topOrder.push(node);

	return topOrder;
}

stack<int> compTopOrder(vector<pair<int, int>> adjList[], int n) {
	stack<int> topOrder;

	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, visited,adjList, topOrder);
		}
	}

	return topOrder;	
}

// void printSt(stack<int> st) {
// 	while(!st.empty()) {
// 		cout << st.top() << endl;
// 		st.pop();
// 	}
// }


vector<int> compShortDist(vector<pair<int, int>> adjList[], int n, int src) {
	vector<int> dist(n, INT_MAX);

	stack<int> topOrder = compTopOrder(adjList, n);

	// int top = topOrder.top();
	// topOrder.pop();

	dist[src] = 0;

	while(!topOrder.empty()) {
		int top = topOrder.top();
		topOrder.pop();

		// Not visited before
		if (dist[top] != INT_MAX) {
			for (auto it : adjList[top]) {
				if (dist[top] + it.second < dist[it.first]) {
					dist[it.first] = dist[top] + it.second;
				}
			}
		}
	}




	// printSt(topOrder);
	// for (auto &x : topOrder) {
	// 	cout << x << endl;
	// }

	return dist;
}

int main() {
	int n = 6;
	vector<pair<int, int>> adjList[n];

	adjList[0].push_back(make_pair(1, 2));
	adjList[0].push_back(make_pair(4, 1));

	adjList[1].push_back(make_pair(2, 3));
	
	adjList[2].push_back(make_pair(3, 6));

	adjList[4].push_back(make_pair(2, 2));
	adjList[4].push_back(make_pair(5, 4));

	adjList[5].push_back(make_pair(3, 1));
	
	int src = 0;
	vector<int> shortDist = compShortDist(adjList, n, src);
	
	for (int i = 0; i < shortDist.size(); i++) {
		cout << "Distance from " << src << " to " << i << " is " << shortDist[i] << endl;
	}

	return 0;
}