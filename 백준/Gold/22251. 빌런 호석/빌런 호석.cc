#include <bits/stdc++.h>
using namespace std;

int n, k, p, x; // 1~n층. k자리로 층수 표시. 1~p개 반전. 현재 실제 위치 x층
vector<vector<int>> led; // led[i]: i 표시하는 led 번호들. 0 사용안함 1 사용함
vector<vector<int>> rev; // rev[i][j]: i->j 반전 개수
string x_str;
int res; // 반전 경우의 수

void init_led(){
    led.resize(10, vector<int>(7, 1));

    led[0][1] = 0;
    for(int i = 0; i <= 4; i++) led[1][i] = 0;
    led[2][3] = 0, led[2][6] = 0;
    led[3][3] = 0, led[3][4] = 0;
    for(int i = 0; i <= 4; i += 2) led[4][i] = 0;
    led[5][4] = 0, led[5][5] = 0;
    led[6][5] = 0;
    for(int i = 1; i <= 4; i++) led[7][i] = 0;
    led[9][4] = 0;
}

void init_reverse(){
    rev.resize(10, vector<int>(10, 0));

    for(int i = 0; i < 10; i++){
        for(int j = i + 1; j < 10; j++){
            for(int x = 0; x < 7; x++){
                if(led[i][x] != led[j][x]) {
                    rev[i][j]++;
                    rev[j][i]++;
                }
            }
        }
    }
    /*
0: 0 4 3 3 4 3 2 3 1 2
1: 4 0 5 3 2 5 6 1 5 4
2: 3 5 0 2 5 4 3 4 2 3
3: 3 3 2 0 3 2 3 2 2 1
4: 4 2 5 3 0 3 4 3 3 2
5: 3 5 4 2 3 0 1 4 2 1
6: 2 6 3 3 4 1 0 5 1 2
7: 3 1 4 2 3 4 5 0 4 3
8: 1 5 2 2 3 2 1 4 0 1
9: 2 4 3 1 2 1 2 3 1 0
    */
}

void dfs(int depth, int rev_cnt){
    if(depth == k){
        if(rev_cnt != 0){
            int sum = 0;
            for(int i = 0; i < depth; i++){
                sum = sum * 10 + (x_str[i] - '0');
            }
            if(sum >= 1 && sum <= n) res++;
        }
        return;
    }

    // rev[i][j]
    int i = x_str[depth] - '0';
    for(int j = 0; j < 10; j++){
        if(rev_cnt + rev[i][j] <= p) {
            x_str[depth] = j + '0';
            dfs(depth + 1, rev_cnt + rev[i][j]);
            x_str[depth] = i + '0';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> p >> x;

    init_led();
    init_reverse();

    // k자리 맞추기
    x_str = "";
    int tmp = x;
    while(tmp){
        char c = '0' + (tmp % 10);
        x_str = c + x_str;
        tmp /= 10;
    }
    while(x_str.length() < k) x_str = "0" + x_str;

    res = 0;
    dfs(0, 0);
    cout << res << '\n';

    return 0;
}
