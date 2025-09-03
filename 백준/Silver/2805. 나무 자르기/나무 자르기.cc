#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	sort(h.begin(), h.end());

	ll start = 0;
	ll end = h[n - 1];
	ll ans = -1;
	while (start <= end) {
		ll mid = (start + end) / 2;
		ll sum = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (h[i] > mid) sum += (h[i] - mid);
			else break;
		}

		if (sum >= m) {
			ans = mid;
			// higher
			start = mid + 1;
		}
		else {
			// lower
			end = mid - 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
