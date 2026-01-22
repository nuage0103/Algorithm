#include <stdio.h>
#include <stdlib.h>

/*
테트로미노  L , ㄴ, ㅡ , ㅁ, ㅗ 회전/대칭
각 좌표별로 테트로미노 회전/대칭시켜 최대합 갱신
*/

int map[501][501];
int visited[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N, M;
int max = 0;

/*
dfs에서 상하좌우 4방향(dx, dy) 탐색하면 ㅗ 제외한 모양 모든 회전/대칭 탐색 가능
상하좌우 이동순서에 따라 주어진 모양과 다른 불필요한 경우도 탐색할 가능성 있음
4칸만 이동한 후 종료하도록 강제 : depth 변수 두어 4인 경우에만 최대값 갱신

visited배열로 방문한 좌표 1로 표시
dfs탐색 끝난 후(시작점으로부터 4칸 탐색) 다른 경로 탐색 위해 0으로 표시(백트래킹)
0으로 표시하여
1) 현재 위치에서 다른 테트로미노 모양 탐색
2) 다른 위치를 시작점으로 두어 새로 탐색
을 가능하게 함
*/
void dfs(int x, int y, int depth, int sum){
    if(depth == 4){
        if(sum > max) max = sum;
        return;
    }

    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx >= 0 && ny >= 0 && nx < N && ny < M){
            if(!visited[nx][ny]){
                visited[nx][ny] = 1; // 방문
                dfs(nx, ny, depth + 1, sum + map[nx][ny]);
                visited[nx][ny] = 0; // 백트래킹
            }
        }
    }
    
}

void T(int x, int y){
    // (x, y)가 각 방향의 중심점
    int sum;
    // ㅗ
    if(x-1 >= 0 && y-1 >= 0 && y+1 < M){
        sum = map[x][y] + map[x-1][y] + map[x][y-1] + map[x][y+1];
        if(sum > max) max = sum;
    }
    // ㅜ
    if(x+1 < N && y-1 >= 0 && y+1 < M){
        sum = map[x][y] + map[x+1][y] + map[x][y-1] + map[x][y+1];
        if(sum > max) max = sum;
    }
    // ㅏ
    if(y+1 < M && x-1 >= 0 && x+1 < N){
        sum = map[x][y] + map[x-1][y] + map[x+1][y] + map[x][y+1];
        if(sum > max) max = sum;
    }
    // ㅓ
    if(y-1 >= 0 && x-1 >= 0 && x+1 < N){
        sum = map[x][y] + map[x-1][y] + map[x+1][y] + map[x][y-1];
        if(sum > max) max = sum;
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &map[i][j]);
        }
    }
    
    // dfs() : 나머지 4개 모양
    // T() : ㅗ 모양, depth = 3이므로 따로 탐색
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visited[i][j] = 1;
            dfs(i, j, 1, map[i][j]);
            visited[i][j] = 0;

            T(i, j);
        }
    }
    printf("%d\n", max);

    return 0;
}