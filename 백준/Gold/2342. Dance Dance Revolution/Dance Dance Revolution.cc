#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> inp;
int weight[5][5]; // [from][to]
int dp[100001][5][5]; // [stage][l_coor][r_coor] = min weight sum
#define INF 1000000

int solve(int stage, int l, int r) {
	if (stage == n - 1) return 0;
	// 중점 아니면 왼, 오 같은 지점에 못있음
	if ((l != 0 && r != 0) && l == r) return INF;

	// 이미 계산함
	if (dp[stage][l][r] != -1) return dp[stage][l][r];
	
	int next = inp[stage + 1];
	int move_left = solve(stage + 1, next, r) + weight[l][next];
	int move_right = solve(stage + 1, l, next) + weight[r][next];
	dp[stage][l][r] = min(move_left, move_right);

	return dp[stage][l][r];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	inp.push_back(0); // 중점에서 시작
	int tmp;
	while (1) {
		cin >> tmp;
		if (!tmp) break;

		inp.push_back(tmp);
	}

	// 가중치 계산
	int dir[4] = { 1, 2, 3, 4 };
	for (int i = 0; i <= 4; i++) weight[i][i] = 1; // 연속 같은 지점: 힘1
	for (int i = 1; i <= 4; i++) weight[0][i] = 2; // 중점 -> 1~4: 힘2
	weight[1][3] = weight[3][1] = 4;
	weight[2][4] = weight[4][2] = 4; // 1~4 -> 반대편: 힘4
	for (int i = 1; i <= 4; i++) {
		int j = i - 1;
		weight[i][dir[(j - 1 + 4) % 4]] = 3;
		weight[i][dir[(j + 1) % 4]] = 3;
	} // 1~4 -> 중점 아닌 인접: 힘3

	// 가중치 최소합 계산
	n = inp.size();
	fill(&dp[0][0][0], &dp[n - 1][4][4] + 1, -1);
	cout << solve(0, 0, 0) << '\n';

	return 0;
}