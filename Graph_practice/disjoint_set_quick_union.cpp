#include<iostream>
#include<vector>

using namespace std;

/*
	Time complexity: 
		find : O(n)
		connected : O(n)
		unionSet: O(h = n) in worst case but on average > quick_find
	
	Space complexity: O(n)

	n = number of nodes in graph.
	h = height of the tree.
*/

class UnionFind{
public:
	UnionFind(int sz) : root(sz) {
		for (int i = 0; i < sz; i++) {
			root[i] = i;
		}
	}

	int find(int x) {
		while(x != root[x]) {
			x = root[x];
		}
		return x;
	}

	void unionSet(int u, int v) {
		int rootU = find(u);
		int rootV = find(v);

		if (rootU != rootV) {
			root[rootV] = rootU;
		}
	}

	bool connected(int u, int v) {
		return find(u) == find(v);
	}


private:
	vector<int> root;
};


int main() {
	cout << boolalpha;
	UnionFind uf(10);

	uf.unionSet(1, 2);
	uf.unionSet(2, 5);
	uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);

    cout << uf.connected(1, 5) << endl;  // true
    cout << uf.connected(5, 7) << endl;  // true
    cout << uf.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9, 4);
    cout << uf.connected(4, 9) << endl;  // true

	return 0;
}