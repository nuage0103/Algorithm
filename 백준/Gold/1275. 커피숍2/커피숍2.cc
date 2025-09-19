#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> idx_tree;
int leaf;

void update(int idx, ll val) {
	idx += leaf;
	idx_tree[idx] = val;
	while (idx > 1) {
		idx /= 2;
		idx_tree[idx] = idx_tree[idx * 2] + idx_tree[idx * 2 + 1];
	}
}

ll query(int start, int end) {
	ll sum = 0;
	start += leaf;
	end += leaf;

	while (start <= end) {
		if (start % 2 == 1) {
			// right child
			sum += idx_tree[start];
		}
		if (end % 2 == 0) {
			// left child
			sum += idx_tree[end];
		}

		start = (start + 1) / 2;
		end = (end - 1) / 2;
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	// make tree
	leaf = 1;
	while (leaf < n) {
		leaf *= 2;
	}
	idx_tree.resize(leaf * 2, 0);
	for (int i = 0; i < n; i++) {
		int idx = leaf + i;
		// leaf
		cin >> idx_tree[idx];

		// parent
		while (idx > 1) {
			idx /= 2;
			idx_tree[idx] = idx_tree[idx * 2] + idx_tree[idx * 2 + 1];
		}
	}

	for (int i = 0; i < q; i++) {
		int x, y, a; // 1 - base idx
		ll b;
		cin >> x >> y >> a >> b;

		// query: subsum
		if (x > y) swap(x, y);
		cout << query(x - 1, y - 1) << '\n';
		// update
		update(a - 1, b);
	}

	return 0;
}