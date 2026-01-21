#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> height; // 높이
vector<vector<int>> fall; // 0S, 1F 기록
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0}; // 0동 1서 2남 3북
int score;

void attack(int x, int y, int d){
    if(fall[x][y]) return;

    int h = height[x][y];
    for(int i=0; i<h; i++){
        if(x < 0 || x >= n || y < 0 || y >=m) break;

        if(!fall[x][y]){
            fall[x][y] = 1;
            score++;
            h = max(h, height[x][y] + i);
        }

        x += dx[d];
        y += dy[d];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int r;
    cin >> n >> m >> r;
    height.resize(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> height[i][j];
        }
    }

    fall.resize(n, vector<int>(m, 0)); // 모두 S(0)
    score = 0;
    for(int i=0; i<r; i++){
        int x, y;
        char d;
        cin >> x >> y >> d; // 공격
        x--; y--;
        if(d == 'E') attack(x, y, 0);
        else if(d == 'W') attack(x, y, 1);
        else if(d == 'S') attack(x, y, 2);
        else if(d == 'N') attack(x, y, 3);

        cin >> x >> y; // 수비
        x--; y--;
        fall[x][y] = 0;
    }

    cout << score << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!fall[i][j]) cout << "S ";
            else cout << "F ";
        }
        cout << '\n';
    }

    return 0;
}
