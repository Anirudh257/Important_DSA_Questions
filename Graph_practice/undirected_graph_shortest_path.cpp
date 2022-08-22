#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

// Time complexity: O(V + E) + O(V)
// Space complexity: O(V + E) for adjacency list + O(V) for queue + O(V) for distance vector

vector<int> compShortDist(vector<int> adjList[], int src, int n) {
	vector<int> dist(n, INT_MAX);

	queue<int> q;

	dist[src] = 0;
	q.push(src);

	while(!q.empty()) {
		int top = q.front();
		q.pop();

		int srcNodeDist = dist[top];

		for (int neigh : adjList[top]) {
			int currDist = dist[neigh];
			int srcNeighDist = srcNodeDist + 1;

			if (srcNeighDist < currDist) {
				dist[neigh] = srcNeighDist;
				q.push(neigh);
			}
		}

	}

	return dist;
}


int main() {
	int n = 9;
	vector<int> adjList[n];

	adjList[0].push_back(1);
	adjList[0].push_back(3);

	adjList[1].push_back(0);
	adjList[1].push_back(2);
	adjList[1].push_back(3);

	adjList[2].push_back(1);
	adjList[2].push_back(6);

	adjList[3].push_back(0);
	adjList[3].push_back(4);

	adjList[4].push_back(3);
	adjList[4].push_back(5);

	adjList[5].push_back(4);
	adjList[5].push_back(6);

	adjList[6].push_back(2);
	adjList[6].push_back(5);
	adjList[6].push_back(7);
	adjList[6].push_back(8);

	adjList[7].push_back(6);
	adjList[7].push_back(8);

	adjList[8].push_back(6);
	adjList[8].push_back(7);

	int src = 0;
	vector<int> shortestDist = compShortDist(adjList, src, n);

	for (int i = 0; i < shortestDist.size(); i++) {
		cout << "Shortest Distance from " << src << " to " << i  << " is " << shortestDist[i] << endl;
	}

	return 0;
}