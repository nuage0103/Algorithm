#include <bits/stdc++.h>
using namespace std;

int n, l, r;
vector<vector<int>> graph;
typedef pair<int, int> pii;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool bfs(int start_x, int start_y, vector<vector<int>>& visited){
    queue<pii> q;
    vector<pii> coor;
    q.push({start_x, start_y});
    coor.push_back({start_x, start_y});
    int sum = graph[start_x][start_y];
    visited[start_x][start_y] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;

            int diff = abs(graph[x][y] - graph[nx][ny]);
            if(diff >= l && diff <= r){
                q.push({nx, ny});
                coor.push_back({nx, ny});
                sum += graph[nx][ny];
                visited[nx][ny] = 1;
            }
        }
    }

    int cnt = (int)coor.size();
    if(cnt == 1) return false;

    int val = sum / cnt;
    for(int i = 0; i < cnt; i++){
        int x = coor[i].first;
        int y = coor[i].second;
        graph[x][y] = val;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r;
    graph.resize(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> graph[i][j];
        }
    }

    int res = 0; // ~2000
    while(1){
        bool change = false;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]) {
                    if(bfs(i, j, visited)) change = true;
                }
            }
        }
        if(!change) break;
        res++;
    }
    cout << res << '\n';

    return 0;
}
