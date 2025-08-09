#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long a[4001], b[4001], c[4001], d[4001];
vector<long long> s;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %lld %lld", &a[i], &b[i], &c[i], &d[i]);
	}

	// A, B 합 배열 S
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			s.push_back(a[i] + b[j]);
		}
	}
	sort(s.begin(), s.end());

	// C, D 합 : S에서 (-합) 값 존재 여부 탐색

	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long tmp = (c[i] + d[j]) * (-1);

			// target 없으면 low_idx, up_idx = n
			int low_idx = lower_bound(s.begin(), s.end(), tmp ) - s.begin();
			int up_idx = upper_bound(s.begin(), s.end(), tmp) - s.begin();
			cnt += (up_idx - low_idx);
		}
	}

	printf("%lld\n", cnt);

	return 0;
}