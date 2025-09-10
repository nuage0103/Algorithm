#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, m;
	cin >> t >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> a_sum;
	for (int i = 0; i < n; i++) {
		ll sum = a[i];
		a_sum.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += a[j];
			a_sum.push_back(sum);
		}
	}

	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	vector<ll> b_sum;
	for (int i = 0; i < m; i++) {
		ll sum = b[i];
		b_sum.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += b[j];
			b_sum.push_back(sum);
		}
	}

	sort(b_sum.begin(), b_sum.end());

	/*
	lower_bound(begin, end, target): >= target 인 첫번째 원소의 주소
	upper_bound(begin, end, target): > target 인 첫번째 원소의 주소
	low = lower_bound() - begin(), up = upper_bound() - begin()
	up - low = target의 개수

	데이터가 모두 < target : low, up = begin
	데이터가 모두 > target : low, up = end
	*/
	ll res = 0;
	for (int i = 0; i < a_sum.size(); i++) {
		ll target = t - a_sum[i];

		int low = lower_bound(b_sum.begin(), b_sum.end(), target) - b_sum.begin();
		int up = upper_bound(b_sum.begin(), b_sum.end(), target) - b_sum.begin();

		res += (up - low); // target 없으면 up-low = 0
	}

	cout << res << '\n';

	return 0;
}