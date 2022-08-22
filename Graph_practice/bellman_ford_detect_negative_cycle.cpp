#include<iostream>
#include<vector>
#include<utility>
#include<climits>

using namespace std;

/* 
	Time complexity: O(N*E), N = number of nodes, E = number of edges
	Space complexity: O(N)
*/

struct node {
	int u;
	int v;
	int wt;

	node(int first, int second, int weight) {
		u = first;
		v = second;
		wt = weight;
	}
};

int main() {
	int n = 6, m = 7;

	vector<node> edges;

	edges.push_back(node(0, 1, 5));
	edges.push_back(node(1, 2, -2));
	edges.push_back(node(1, 5, -3));
	edges.push_back(node(2, 4, 3));
	edges.push_back(node(3, 2, 6));
	edges.push_back(node(3, 4, -2));
	edges.push_back(node(5, 3, 1));

	int src = 0;
    int inf = 10000000; 

 	vector<int> dist(n, inf);
 	dist[src] = 0;
 	int i = 0;

	while(i <= n - 1) {
		for (auto it : edges) {
			if (dist[it.u] + it.wt < dist[it.v]) {
				dist[it.v] = dist[it.u] + it.wt;
			}
		}
		i++;
	}

	bool flag = false;

	for (auto it : edges) {
		if (dist[it.u] + it.wt < dist[it.v]) {
			cout << "There is a negative cycle" << endl;
			flag = true;
			break;
		}
	}

	if (!flag) {
		for (auto &x : dist) {
			cout << x << endl;
		}		
	}

	return 0;
}