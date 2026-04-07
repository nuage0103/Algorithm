#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<string> board;
int res;

void dfs(int x, int y, int dist, int mask){
    res = max(res, dist);

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

        int b = 1 << (board[nx][ny] - 'A');
        if(mask & b) continue;

        dfs(nx, ny, dist + 1, mask | b);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    board.resize(r);
    for(int i = 0; i < r; i++){
        cin >> board[i];
    }

    res = -1;
    dfs(0, 0, 1, 1 << (board[0][0] - 'A'));
    cout << res << '\n';

    return 0;
}
