#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> chosen;
int res;

int dist() {
	int cnt = house.size();
	vector<int> d(cnt, INT_MAX);

	for (int i = 0; i < cnt; i++) {
		pair<int, int> h = house[i];
		for(int j=0; j<m; j++){
			d[i] = min(d[i], abs(h.first - chosen[j].first) + abs(h.second - chosen[j].second));
		}
	}

	int sum = 0;
	for (int i = 0; i < cnt; i++) {
		sum += d[i];
	}

	return sum;
}

void dfs(int depth, int cur) {
	// chicken 조합 선택
	if (depth == m) {
		res = min(res, dist());
		return;
	}

	for (int i = cur; i < chicken.size(); i++) {
		chosen.push_back({ chicken[i].first, chicken[i].second });
		dfs(depth + 1, i + 1);
		chosen.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 0 빈칸, 1 집, 2 치킨집
			int x;
			cin >> x;
			if (x == 1) house.push_back({ i, j });
			else if (x == 2) chicken.push_back({ i, j });
		}
	}

	res = INT_MAX;
	dfs(0, 0);
	cout << res << '\n';
	
	return 0;
}
