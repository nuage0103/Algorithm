#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
vector<pair<int, int>> jew; // 보석 {무게, 가격}
vector<int> c; // 가방 최대 수용 무게

priority_queue<int> pq; // 가격, max heap
int jew_idx = 0;

int bag_max_price(int c_idx) {
	while (jew_idx < n && c[c_idx] >= jew[jew_idx].first) {
		pq.push(jew[jew_idx++].second);
	}

	if (!pq.empty()) {
		int p = pq.top();
		pq.pop();

		return p;
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	jew.resize(n);
	c.resize(k);

	for (int i = 0; i < n; i++) {
		cin >> jew[i].first >> jew[i].second;
	}

	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}

	// 무게 오름차순 정렬
	// sort(jew.begin(), jew.end()); 무게(first)가 동일하면 가격(second)기준 오름차순
	sort(jew.begin(), jew.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first < b.first;
		}); // 무게(first)가 동일하면 가격(second)기준 내림차순

	sort(c.begin(), c.end());

	long long sum = 0;
	for (int i = 0; i < k; i++) {
		// 수용 무게 적은 가방부터 최대 가격으로 채우기
		sum += bag_max_price(i);
	}
	
	cout << sum << '\n';
	
	return 0;
}