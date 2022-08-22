#include<iostream>
#include<vector>

using namespace std;

/*
	Time complexity: 
		find : O(alpha n)
		UnionSet: O(alpha n)
		Connected: O(alpha n) because of balanced tree + path compression
		
		alpha(n) = inverse ackermann function(n), which is O(1) in average

	Space complexity: O(n)
	
	where n = #nodes
*/


class UnionFind {
public:
	UnionFind(int sz) : root(sz), rank(sz) {
		for (int i = 0; i < sz; i++) {
			root[i] = i;
			rank[i] = 1;
		}
	}

	int find(int x) {
		// while (x != root[x]) {
		// 	x = root[x];
		// }
		// return x;
		if (x == root[x]) {
			return x;
		}
		return root[x] = find(root[x]);
	}

	void UnionSet(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);

		if (rootX != rootY) {
			if (rank[rootX] > rank[rootY]) {
				root[rootY] = rootX;
			}
			else if (rank[rootX] < rank[rootY]) {
				root[rootX] = rootY;
			}
			else {
				root[rootY] = rootX;
				rank[rootX]++;
			}			
		}
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}




private:
	vector<int> root;
	vector<int> rank;
};

int main() {

	cout << boolalpha;

	UnionFind uf(10);

	uf.UnionSet(0, 1);
	uf.UnionSet(1, 2);
	uf.UnionSet(2, 3);
	uf.UnionSet(3, 4);

	cout << uf.connected(0, 4) << endl;
	cout << uf.connected(1, 4) << endl;
	cout << uf.connected(1, 5) << endl;



	return 0;
}