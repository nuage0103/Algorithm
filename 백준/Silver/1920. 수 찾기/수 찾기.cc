#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	int a[100001];
	int b[100001];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}

	sort(a, a + n);

	for (int i = 0; i < m; i++) {
		if (binary_search(a, a + n, b[i])) printf("1\n");
		else printf("0\n");
	}

	return 0;
}
