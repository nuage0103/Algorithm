#include<bits/stdc++.h>
using namespace std;

string res;

void bfs(int a, int b){
    if(a == b) return;

    queue<pair<int, string>> q;
    vector<int> visited(10000);
    q.push({a, ""});
    visited[a] = 1;

    char op[4] = {'D', 'S', 'L', 'R'};

    while(!q.empty()){
        int cur = q.front().first;
        string path = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx;
            if(i == 0) nx = (cur * 2) % 10000;
            else if(i == 1) nx = (cur == 0)? 9999 : cur - 1;
            else if(i == 2) nx = (cur % 1000) * 10 + (cur / 1000);
            else nx = (cur % 10) * 1000 + (cur / 10);

            if(nx == b) {
                res = path + op[i];
                return;
            }
            if(visited[nx]) continue;

            visited[nx] = 1;
            q.push({nx, path + op[i]});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b; // 0~9999
        res = "";
        bfs(a, b);
        cout << res << '\n';
    }

    return 0;
}
