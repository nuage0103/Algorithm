#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[100001];

int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int min_len = 100001;
	int low = 0;
	int high = 0;
	int sum = arr[0];
	while (low <= high) {
		if (high == n) break;

		if (sum < s) {
			sum += arr[++high];
		}
		else {
			min_len = min(min_len, high - low + 1);
			sum -= arr[low++];
		}
	}

	if(min_len <= n) printf("%d\n", min_len);
	else printf("0\n");

	return 0;
}
