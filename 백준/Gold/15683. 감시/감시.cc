#include <bits/stdc++.h>
using namespace std;

/*
1~6
0 / #(-1): 사각지대 / 감시

dfs: 모든 카메라 방향 결정 이후 사각지대(0 개수) 최소 갱신
*/

typedef pair<int, int> pii;
typedef struct{
    int x, y;
    int d; // cctv 종류
}Cam;

int n, m, k;
vector<vector<int>> graph;
vector<Cam> cam;
vector<vector<vector<pii>>> dir;
int min_cnt;

void init_dir(){
    dir.resize(6);

    dir[1].resize(4);
    dir[1][0].push_back({1, 0});
    dir[1][1].push_back({-1, 0});
    dir[1][2].push_back({0, 1});
    dir[1][3].push_back({0, -1});

    dir[2].resize(2);
    dir[2][0].push_back({1, 0}); dir[2][0].push_back({-1, 0});
    dir[2][1].push_back({0, 1}); dir[2][1].push_back({0, -1});

    dir[3].resize(4);
    dir[3][0].push_back({1, 0}); dir[3][0].push_back({0, 1});
    dir[3][1].push_back({1, 0}); dir[3][1].push_back({0, -1});
    dir[3][2].push_back({-1, 0}); dir[3][2].push_back({0, 1});
    dir[3][3].push_back({-1, 0}); dir[3][3].push_back({0, -1});

    dir[4].resize(4);
    dir[4][0].push_back({1, 0}); dir[4][0].push_back({-1, 0}); dir[4][0].push_back({0, 1});
    dir[4][1].push_back({1, 0}); dir[4][1].push_back({-1, 0}); dir[4][1].push_back({0, -1});
    dir[4][2].push_back({1, 0}); dir[4][2].push_back({0, -1}); dir[4][2].push_back({0, 1});
    dir[4][3].push_back({0, -1}); dir[4][3].push_back({-1, 0}); dir[4][3].push_back({0, 1});

    dir[5].resize(1);
    dir[5][0].push_back({1, 0});
    dir[5][0].push_back({-1, 0});
    dir[5][0].push_back({0, 1});
    dir[5][0].push_back({0, -1});
}

void dfs(int depth){
    if(depth == k){
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!graph[i][j]) cnt++;
            }
        }
        min_cnt = min(min_cnt, cnt);
        return;
    }

    int x = cam[depth].x;
    int y = cam[depth].y;
    int d = cam[depth].d;
    vector<pii> repair;
    for(int i=0; i<dir[d].size(); i++){
        // 감시영역. 0 -> -1
        for(int j=0; j<dir[d][i].size(); j++){
            int dx = dir[d][i][j].first;
            int dy = dir[d][i][j].second;

            int nx = x;
            int ny = y;
            while(1){
                nx += dx;
                ny += dy;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) break;
                if(graph[nx][ny] == 6) break;

                if(!graph[nx][ny]) {
                    graph[nx][ny] = -1;
                    repair.push_back({nx, ny});
                }
            }
        }

        dfs(depth+1);
        // 백트래킹. -1 -> 0
        for(auto [xx, yy]: repair) graph[xx][yy] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    // 0빈칸, 6벽, 1~5 cctv
    // 1 한방향 / 2 반대방향 / 3 직각방향 / 4 세방향 / 5 네방향
    graph.resize(n, vector<int>(m));
    k = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> graph[i][j];
            if(graph[i][j] >= 1 && graph[i][j] <= 5) {
                k++;
                cam.push_back({i, j, graph[i][j]});
            }
        }
    }

    init_dir();

    min_cnt = 100;
    dfs(0);
    cout << min_cnt << '\n';

    return 0;
}
