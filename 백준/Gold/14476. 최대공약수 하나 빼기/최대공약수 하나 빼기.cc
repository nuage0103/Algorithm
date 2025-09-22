#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	vector<int> l_gcd(n); // [i]: 0~i의 gcd
	vector<int> r_gcd(n); // [i]: i~n-1의 gcd
	l_gcd[0] = num[0];
	for (int i = 1; i < n; i++) {
		l_gcd[i] = gcd(l_gcd[i - 1], num[i]);
	}

	r_gcd[n - 1] = num[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		r_gcd[i] = gcd(r_gcd[i + 1], num[i]);
	}

	// k
	// n-1개 수의 gcd: l_gcd[k-1](0~k-1), r_gcd[k+1](k+1~n-1)의 gcd
	int max_gcd = -1;
	int max_k = 0;
	for (int k = 0; k < n; k++) {
		int x;
		if (k == 0) x = r_gcd[k + 1];
		else if (k == n - 1) x = l_gcd[k - 1];
		else x = gcd(l_gcd[k - 1], r_gcd[k + 1]);

		if (max_gcd < x && num[k] % x != 0) {
			max_gcd = x;
			max_k = num[k];
		}
	}

	if (max_gcd != -1) cout << max_gcd << ' ' << max_k << '\n';
	else cout << max_gcd << '\n';

	return 0;
}