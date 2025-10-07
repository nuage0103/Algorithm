#include <iostream>
#include <vector>
using namespace std;

#define INF 20000000
int n;
vector<vector<int>> w;
vector<vector<int>> dp;

int dfs(int cur, int visit) {
	if (visit == (1 << n) - 1) {
		if (w[cur][0] == 0) return INF;
		else return w[cur][0];
	}

	if (dp[cur][visit] != -1) return dp[cur][visit];

	dp[cur][visit] = INF;
	for (int i = 0; i < n; i++) {
		if (!w[cur][i]) continue;
		if (visit & (1 << i)) continue;

		dp[cur][visit] = min(dp[cur][visit], w[cur][i] + dfs(i, visit | (1 << i)));
	}
	return dp[cur][visit];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	w.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	dp.resize(n, vector<int>(1 << n, -1));
	cout << dfs(0, 1) << '\n';

	return 0;
}