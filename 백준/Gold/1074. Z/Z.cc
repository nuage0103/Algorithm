#include<bits/stdc++.h>
using namespace std;

int r, c;
int cnt;
bool check = false;

void solve(int size, int x, int y){
    if(check) return;

    if(!(x <= r && r < x + size && y <= c && c < y + size)){
        cnt += size * size;
        return;
    }
    if(size == 1 && x == r && y == c) {
        check = true;
        return;
    }

    size /= 2;
    solve(size, x, y);
    solve(size, x, y + size);
    solve(size, x + size, y);
    solve(size, x + size, y + size);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n >> r >> c;

    cnt = 0;
    solve(1 << n, 0, 0);

    cout << cnt << '\n';

    return 0;
}
