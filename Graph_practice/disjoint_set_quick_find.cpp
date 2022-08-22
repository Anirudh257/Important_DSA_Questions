#include<iostream>
#include<vector>
using namespace std;

/* Time complexity:
	find: O(1)
	unionSet: O(n), n = number of nodes
	connected: O(1)

	Space complexity: O(n)
*/

class UnionFind {
public:
	UnionFind(int sz) : root(sz) {
		for (int i = 0; i < sz; i++) {
			root[i] = i;
		}
	}

	int find(int x) {
		return root[x];
	}

	void unionSet(int u, int v) {
		int rootU = find(u);
		int rootV = find(v);

		if (rootU != rootV) {
			for (int i = 0; i < root.size(); i++) {
				if (root[i] == rootV) {
					root[i] = rootU;
				}
			}
		}
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
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