#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1}; // 0가로, 1세로, 2대각
int res;

void dfs(int x, int y, int dir){
    if(x == n-1 && y == n-1){
        res++;
        return;
    }

    for(int i=0; i<3; i++){
        if(dir == 0 && i == 1) continue;
        if(dir == 1 && i == 0) continue;

        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= n || ny >= n) continue;
        if(graph[nx][ny]) continue;
        if(i == 2){
            if(graph[x][ny] || graph[nx][y]) continue;
        }

        dfs(nx, ny, i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    graph.resize(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> graph[i][j];
        }
    }

    res = 0;
    dfs(0, 1, 0);
    cout << res << '\n';

    return 0;
}
