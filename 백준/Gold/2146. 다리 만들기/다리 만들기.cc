#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<vector<int>> board;
vector<vector<int>> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int min_dist;

void bfs_group(int stx, int sty, int group){
    queue<pair<int, int>> q;
    q.push({stx, sty});
    board[stx][sty] = group;
    visited[stx][sty] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny] != -1) continue; // 0 / 다른 구역 육지

            visited[nx][ny] = 1;
            board[nx][ny] = group;
            q.push({nx, ny});
        }
    }
}

void bfs_dist(){
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j]){
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int d = dist[x][y];
        q.pop();

        int g = board[x][y];
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            // 바다, 구역 미정
            if(board[nx][ny] == 0){
                board[nx][ny] = g;
                dist[nx][ny] = d + 1;
                q.push({nx, ny});
            }

            // 다른 구역
            if(board[nx][ny] != g){
                min_dist = min(min_dist, d + dist[nx][ny]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    board.resize(n, vector<int>(n));
    vector<pair<int, int>> land;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                board[i][j] = -1;
                land.push_back({i, j});
            }
        }
    }

    visited.resize(n, vector<int>(n, 0));
    int group = 1; // 0 바다, 1 ~ 육지
    for(int i = 0; i < land.size(); i++){
        int x = land[i].first;
        int y = land[i].second;

        if(visited[x][y]) continue;
        bfs_group(x, y, group);
        group++;
    }

    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << "  ";
        }
        cout << '\n';
    }*/

    min_dist = 1e4;
    bfs_dist();
    cout << min_dist << '\n';

    return 0;
}
