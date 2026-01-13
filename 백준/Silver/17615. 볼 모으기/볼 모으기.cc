#include <bits/stdc++.h>
using namespace std;

int n;
string ball, ball_r;

int move(char pass){
    int cnt1 = 0;
    int prev = -1;
    while(1){
        int p = ball.find(pass, prev + 1);
        if(p == string::npos) break;

        cnt1 += (p - prev - 1);
        prev = p;
    }

    int cnt2 = 0;
    prev = -1;
    while(1){
        int p = ball_r.find(pass, prev + 1);
        if(p == string::npos) break;

        cnt2 += (p - prev - 1);
        prev = p;
    }

    return min(cnt1, cnt2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ball;
    if(ball.find('B') == string::npos || ball.find('R') == string::npos){
        cout << "0\n";
        return 0;
    }

    int cnt = 1e9;
    ball_r = ball;
    reverse(ball_r.begin(), ball_r.end());
    cnt = min(cnt, move('B'));
    cnt = min(cnt, move('R'));
    cout << cnt << '\n';
    return 0;

    return 0;
}
