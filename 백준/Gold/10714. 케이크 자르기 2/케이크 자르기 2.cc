#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int n;
vector<int> cake;
vector<vector<ll>> dp;
// 선택한 조각의 인접한 조각들 중 선택, 연속적으로 선택범위 확장됨
// dp[start][end]: start+1 ~ end-1 까지 선택한 상태, start/end 중 선택해서 joi 최대합
// dp[i][i] = 0

#define L_MOVE(l) (l - 1 + n) % n // 인접 조각 중 왼쪽으로 확장
#define R_MOVE(r) (r + 1) % n // 오른쪽으로 확장
ll ioi(int, int);
ll joi(int, int);

ll ioi(int start, int end) {
	// 확장 못함
	if (L_MOVE(start) == end || R_MOVE(end) == start) return 0;

	int l = L_MOVE(start);
	int r = R_MOVE(end);
	// 오른쪽 선택: end -> r 확장
	if (cake[l] < cake[r]) return joi(start, r);
	// 왼쪽 선택: l <- start 확장
	else return joi(l, end);
}

ll joi(int start, int end) {
	// 확장 못함
	if (L_MOVE(start) == end || R_MOVE(end) == start) return 0;
	// 이미 구한 범위
	if (dp[start][end] != -1) return dp[start][end];

	int l = L_MOVE(start);
	int r = R_MOVE(end);
	dp[start][end] = max(cake[l] + ioi(l, end), cake[r] + ioi(start, r));
	return dp[start][end];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cake.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> cake[i];
	}

	dp.resize(n, vector<ll>(n, -1));
	ll res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, cake[i] + ioi(i, i));
	}
	cout << res << '\n';

	return 0;
}