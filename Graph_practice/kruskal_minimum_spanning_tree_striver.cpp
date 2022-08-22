#include<iostream>
#include<vector>
#include<algorithm>
#include<vector>

using namespace std;

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

class UnionFind{
public:
	UnionFind(int sz) : root(sz), rank(sz) {
		for (int i = 0; i < sz; i++) {
			root[i] = i;
			rank[i] = 1;
		}
	}

	int findPar(int x) {
		if (x == root[x]) {
			return x;
		}
		return root[x] = findPar(root[x]);
	}

	void unionSet(int u, int v) {
		int rootU = findPar(u);
		int rootV = findPar(v);

		if (rootU != rootV) {
			if (rank[rootU] > rank[rootV]) {
				root[rootV] = rootU;
			}
			else if (rank[rootU] < rank[rootV]) {
				root[rootU] = rootV;
			}
			else {
				root[rootV] = rootU;
				rank[rootU]++;
			}
		}
	}


private:
	vector<int> root;
	vector<int> rank;
};


bool cmp(node a, node b) {
	return a.wt < b.wt;
}

int main() {

	int N = 5, m = 6;

	vector<node> edges;

	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));

	sort(edges.begin(), edges.end(), cmp);

	UnionFind uf(N);

	int minCost = 0;
	vector<pair<int, int>> minSpanTree;

	for (auto it : edges) {
		if (uf.findPar(it.u) != uf.findPar(it.v)) {
			minSpanTree.push_back({it.u, it.v});
			minCost += it.wt;
			uf.unionSet(it.u, it.v);
		}
	}

	cout << minCost << endl;
	for(auto it : minSpanTree) cout << it.first << " - " << it.second << endl; 


	return 0;
}