#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<string> map;
vector<vector<int>> visited;
vector<vector<int>> dp; // [x][y] = (x, y)에서 출발했을 때 최대 이동횟수
bool cycle;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int dfs(int x, int y) {
	// 탐색 종료
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (map[x][y] == 'H') return 0;
	// 무한탐색
	if (cycle) return 0;
	if (visited[x][y]) {
		cycle = true;
		return 0;
	}
	// 이미 탐색한 지점
	if (dp[x][y] != -1) return dp[x][y];

	int dist;
	if (map[x][y] != 'H') dist = map[x][y] - '0';
	else dist = 0;

	visited[x][y] = 1;
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		if (dist) {
			int nx = x + dist * dx[i];
			int ny = y + dist * dy[i];

			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
			if (cycle) {
				visited[x][y] = 0;
				return 0;
			}
		}
	}
	visited[x][y] = 0;
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	map.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	visited.resize(n, vector<int>(m));
	dp.resize(n, vector<int>(m, -1));
	int res = dfs(0, 0);

	if (cycle) cout << -1 << '\n';
	else cout << res << '\n';

	return 0;
}
