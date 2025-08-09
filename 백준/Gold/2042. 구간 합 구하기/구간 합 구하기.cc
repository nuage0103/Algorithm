#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 1000001
int n, m, k; // 개수, 업데이트 횟수, 구간합 연산 횟수
long long num[MAX];
long long index_tree[MAX * 2]; // [1] : root
int cnt;

void make_tree();
void update_tree(int, long long);
long long sub_sum(int, int);

int main() {
	scanf("%d %d %d", &n, &m, &k);

	make_tree();

	for (int i = 0; i < m + k; i++) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		
		if (a == 1) update_tree(b, c);
		if (a == 2) printf("%lld\n", sub_sum(b, c));
		
	}

	return 0;
}

void make_tree() {
	cnt = 1;
	while (cnt < n) {
		cnt *= 2;
	}
	// cnt = 2^depth
	fill(index_tree, index_tree + MAX * 2, 0); // 초기값 설정, 빈 리프노드 채우기

	for (int i = 0; i < n; i++) {
		int idx = cnt + i;
		scanf("%lld", &num[i]);
		// leaf node
		index_tree[idx] = num[i];

		// parent node
		while (idx > 1) {
			idx /= 2;
			index_tree[idx] = index_tree[idx * 2] + index_tree[idx * 2 + 1];
		}
	}

}

void update_tree(int pos, long long num) {
	pos--; // 0 base idx
	int idx = cnt + pos;

	index_tree[idx] = num;
	while (idx > 1) {
		idx /= 2;
		index_tree[idx] = index_tree[idx * 2] + index_tree[idx * 2 + 1];
	}
}

long long sub_sum(int start, int end) {
	start--;
	end--;
	start = cnt + start;
	end = cnt + end ;

	long long sum = 0;

	while (start <= end) {
		if (start % 2 == 1) {
			// right child
			sum += index_tree[start];
		}
		if (end % 2 == 0) {
			// left child
			sum += index_tree[end];
		}
		
		start = (start + 1) / 2;
		end = (end - 1) / 2;
	}

	return sum;
}