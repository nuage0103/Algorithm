#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 100000

int w, h;
int dp[101][101][2][2] = { 0 };
// [x][y] ~ [w][h]까지 경로 수
// [x][y][dir][turn], dir 북(y+)0 동(x+)1, turn false0 true1
// 동/북 이동, 방향 전환 후 2번 이상 같은방향 이동 필요

int path(int x, int y, int dir, int turn) {
	if (x == w && y == h) return 1;
	if (x < 1 || x > w || y < 1 || y > h) return 0;

	if (dp[x][y][dir][turn] != 0) return dp[x][y][dir][turn];

	int& ret = dp[x][y][dir][turn]; // 참조
	if (turn) {
		if (dir == 0) ret += path(x, y + 1, dir, 0) % MOD;
		else ret += path(x + 1, y, dir, 0) % MOD;
	}
	else {
		if (dir == 0) ret += path(x, y + 1, dir, 0) % MOD + path(x + 1, y, !dir, 1) % MOD;
		else ret += path(x+1, y, dir, 0) % MOD + path(x, y+1, !dir, 1) % MOD;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> w >> h;
	
	int res = path(1, 2, 0, 0) % MOD + path(2, 1, 1, 0) % MOD;
	cout << res % MOD << '\n';
	
	return 0;
}