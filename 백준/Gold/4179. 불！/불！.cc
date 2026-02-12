#include<bits/stdc++.h>
using namespace std;

#define INF 10e7
typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int r, c;
    cin >> r >> c;
    vector<string> graph(r);
    queue<pii> qj, qf;
    vector<vector<int>> fire(r, vector<int>(c, -1)); // [r][c]에 불난 시간
    vector<vector<int>> visited(r, vector<int>(c, -1));
    for(int i=0; i<r; i++){
        cin >> graph[i];
        for(int j=0; j<c; j++){
            if(graph[i][j] == 'J'){
                qj.push({i, j});
                visited[i][j] = 0;
            }
            if(graph[i][j] == 'F'){
                qf.push({i, j});
                fire[i][j] = 0;
            }
        }
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    // 불
    while(!qf.empty()){
        int x = qf.front().first;
        int y = qf.front().second;
        int t = fire[x][y];
        qf.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = t + 1;
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(graph[nx][ny] == '#') continue;
            if(fire[nx][ny] != -1) continue;

            fire[nx][ny] = nt;
            qf.push({nx, ny});
        }
    }

    // 지훈
    int min_time = INF;
    while(!qj.empty()){
        int x = qj.front().first;
        int y = qj.front().second;
        int t = visited[x][y];
        qj.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = t + 1;
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) {
                min_time = min(min_time, nt);
                continue;
            }
            if(graph[nx][ny] == '#') continue;
            if(visited[nx][ny] != -1) continue;

            if(fire[nx][ny] == -1 || nt < fire[nx][ny]) {
                visited[nx][ny] = nt;
                qj.push({nx, ny});
            }
        }
    }

    if(min_time != INF) cout << min_time << '\n';
    else cout << "IMPOSSIBLE\n";

    return 0;
}
