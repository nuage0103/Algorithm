#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int a[10001];
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int cnt = 0;
	int left = 0;
	int right = 0;
	int sum = a[0];
	while (1) {
		if (right == n) break;

		// 자연수, >m 좌 축소
		// <m 우 확장
		if (sum < m) {
			sum += a[++right];
		}
		else if (sum > m) {
			sum -= a[left++];
		}
		else {
			cnt++;
			sum += a[++right];
		}
	}
	
	printf("%d\n", cnt);

	return 0;
}