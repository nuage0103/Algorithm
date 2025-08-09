#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

#define MAX 20001
// -10000 ~ 10000, leaf[i] = i-10000의 빈도
#define offset 10000
vector<int> idxtree;
int leaf;

void update(int idx, int val) {
	idx += leaf;
	idxtree[idx] += val;

	while (idx > 1) {
		idx /= 2;
		idxtree[idx] = idxtree[idx * 2] + idxtree[idx * 2 + 1];
	}
}

int query(int mid) {
	int idx = 1;
	while (idx < leaf) {
		if (mid <= idxtree[idx * 2]) {
			// left
			idx = idx * 2;
		}
		else {
			mid -= idxtree[idx * 2];
			// right
			idx = idx * 2 + 1;
		}
	}

	return idx - leaf;
}

int main() {
	int n;
	scanf("%d", &n);

	leaf = 1;
	while (leaf < MAX) {
		leaf *= 2;
	}
	idxtree.resize(leaf * 2, 0);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);

		// leaf[0] : -10000의 빈도
		update(x + offset, 1);
		printf("%d\n", query((idxtree[1] + 1) / 2) - offset);// 중간값
	}

	return 0;
}