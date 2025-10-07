#include <iostream>
#include <vector>
using namespace std;

/*
bitmasking + dp

bit: 지나간 도시를 1로 표시
모든 도시 방문 완료시 11...1 = (1<<n)-1

dp: [cur][bit] 현재 도시 cur, 방문 상태가 bit일 때
남은 도시 다 방문하는 데 드는 최소 추가 비용
*/

int n;
vector<vector<int>> w; // w[i][j]: i->j cost, w[i][i] = 0
vector<vector<int>> cost; // dp
#define INF 20000000

int dfs(int cur, int bit) {
	// 모든 도시 방문 완료
	if (bit == (1 << n) - 1) {
		// cur -> 0(출발점)
		if (!w[cur][0]) return INF; // 경로 없음
		else return w[cur][0];
	}
	// 이미 방문
	if (cost[cur][bit] != -1) return cost[cur][bit];

	// 다음 도시 선택
	cost[cur][bit] = INF;
	for (int i = 0; i < n; i++) {
		if (!w[cur][i]) continue; // cur -> i 경로 없음
		if (bit & (1 << i)) continue; // 이미 방문

		// 다음 도시 i에 대해 최소값 연산
		cost[cur][bit] = min(cost[cur][bit], w[cur][i] + dfs(i, bit | (1 << i)));
	}
	return cost[cur][bit]; // cur 이후 남은 최소 추가 비용
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

	cost.resize(n, vector<int>(1 << n, -1));
	// bit 000..01: 0번 도시(출발점)만 방문한 상태
	cout << dfs(0, 1) << '\n';

	return 0;
}