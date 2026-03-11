#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<vector<int>> color;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0}; // 우, 좌, 상, 하

/*
string(아래~위)
0 흰: 기존 문자열 + 현재 이동 번호
1 빨: reverse
2 파/판 벗어남: 이동방향 반대, 이동o/x
*/

typedef struct{
    int x, y;
    int d;
}Node;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    color.resize(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> color[i][j];
        }
    }

    vector<vector<vector<int>>> board(n + 1, vector<vector<int>>(n + 1));
    vector<Node> info(k + 1);
    for(int i = 1; i <= k; i++){
        int x, y, d;
        cin >> x >> y >> d;
        board[x][y].push_back(i);
        info[i] = {x, y, d - 1};
    }

    int turn = 1;
    while(turn <= 1000){
        for(int i = 1; i <= k; i++){
            int x = info[i].x;
            int y = info[i].y;
            int d = info[i].d;

            int nx = x + dx[d];
            int ny = y + dy[d];
            // 범위밖, 파
            if((nx < 1 || nx > n || ny < 1 || ny > n) || color[nx][ny] == 2){
                d = (d % 2 == 0)? d + 1 : d - 1;
                info[i].d = d;

                nx = x + dx[d];
                ny = y + dy[d];

                if((nx < 1 || nx > n || ny < 1 || ny > n) || color[nx][ny] == 2) continue;
            }

            // 흰, 빨
            vector<int>& cur = board[x][y];
            auto it = find(cur.begin(), cur.end(), i);
            vector<int> move(it, cur.end());
            cur.erase(it, cur.end());

            if(color[nx][ny] == 1) reverse(move.begin(), move.end());
            for(int p: move) {
                board[nx][ny].push_back(p);
                info[p].x = nx;
                info[p].y = ny;
            }

            if(board[nx][ny].size() >= 4) {
                cout << turn << '\n';
                return 0;
            }
        }

        turn++;
    }

    cout << -1 << '\n';

    return 0;
}
