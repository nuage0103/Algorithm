#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int res;
int r, c;
vector<vector<char>> map;

typedef struct {
	int x, y;
	int time;
}Info;

queue<Info> water;
queue<Info> gos;

void bfs() {
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };
	vector<vector<int>> visited_w(r, vector<int>(c)); // 시간 기록, 고슴도치: 물예정으로 이동못함
	vector<vector<int>> visited_g(r, vector<int>(c)); // 방문 여부 기록

	while (!water.empty()) {
		Info cur = water.front();
		water.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			// 범위 밖
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			// 돌, 비버굴
			if (map[nx][ny] == 'X' || map[nx][ny] == 'D') continue;

			// 이동
			if (!visited_w[nx][ny]) {
				water.push({ nx, ny, cur.time + 1 });
				visited_w[nx][ny] = cur.time + 1;
			}
		}
	}

	while (!gos.empty()) {
		Info cur = gos.front();
		gos.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			// 범위 밖
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			// 돌, 물
			if (map[nx][ny] == 'X' || map[nx][ny] == '*') continue;
			// 물 예정
			if (visited_w[nx][ny] > 0 && visited_w[nx][ny] <= cur.time + 1) continue;

			// 비버굴
			if (map[nx][ny] == 'D') {
				res = cur.time + 1;
				return;
			}

			// 이동
			if (!visited_g[nx][ny]) {
				gos.push({ nx, ny, cur.time + 1 });
				visited_g[nx][ny] = 1;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	map.resize(r, vector<char>(c));
	for (int i = 0; i < r; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < c; j++) {
			map[i][j] = tmp[j];
			if (map[i][j] == 'S') {
				gos.push({ i, j, 0 });
			}
			else if (map[i][j] == '*') {
				water.push({ i, j, 0 });
			}
		}
	}

	res = -1;
	bfs();

	if (res > 0) printf("%d\n", res);
	else printf("KAKTUS\n");

	return 0;
}
