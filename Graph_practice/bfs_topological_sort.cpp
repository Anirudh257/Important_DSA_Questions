#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// AKA Kahn's algorithm.

// Time complexity : O(V + E), Space complexity: O(V + E)[graph] + O(V)[queue] + O(V)[indegree]

// Only works for Directed Acyclic Graphs.
// Not working if cycles present or undirected graphs.

class Solution {
public:
	vector<int> compBfsTopSort(vector<int> adj[], int n) {
		
		vector<int> indegree(n, 0);

		for (int i = 0; i < n; i++) {
			for (int neigh : adj[i]) {
				indegree[neigh]++;
			}
		}

		queue<int> q;

		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		vector<int> topOrd;
		
		while(!q.empty()) {
			int top = q.front();
			q.pop();	
			topOrd.push_back(top);

			for (int neigh : adj[top]) {
				indegree[neigh]--;
				if (indegree[neigh] == 0) {
					q.push(neigh);
				}
			}

		}
	return topOrd;
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

	vector<int> bfsOrd = obj.compBfsTopSort(adj, N);

	for (auto &x : bfsOrd) {
		cout << x << endl;
	}

	return 0;
}