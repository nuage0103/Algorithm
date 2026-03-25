#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s[4];
int dir[4]; // 1 시계, -1 반시계, 0 회전안함

void rot(int idx){
    if(dir[idx] == 0) return;

    string &str = s[idx];
    if(dir[idx] == 1){
        // 시계
        str = str[7] + str.substr(0, 7);
    }
    else{
        // 반시계
        str = str.substr(1) + str[0];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 4; i++){
        cin >> s[i];
        dir[i] = 0;
    }

    int k;
    cin >> k;
    while(k--){
        int n, d;
        cin >> n >> d;
        n--;

        // 회전, 방향 결정: 맞닿은 극 다르면 반대 방향으로 회전 / 같으면 회전안함, 전파중단
        dir[n] = d;
        // 우측
        for(int i = n; i < 3; i++){
            if(s[i][2] != s[i+1][6]){
                dir[i+1] = -dir[i];
            }
            else break;
        }
        // 좌측
        for(int i = n; i > 0; i--){
            if(s[i][6] != s[i-1][2]){
                dir[i-1] = -dir[i];
            }
            else break;
        }

        // 회전
        for(int i = 0; i < 4; i++) {
            rot(i);
            dir[i] = 0;
        }
    }

    int res = 0;
    int mul = 1;
    for(int i = 0; i < 4; i++){
        if(s[i][0] == '1') res += mul;
        mul *= 2;
    }
    cout << res << '\n';

    return 0;
}
