#include<bits/stdc++.h>
using namespace std;

int n, m, h;
vector<vector<int>> graph;
bool check;

bool traverse(){
    for(int b=1; b<=n; b++){
        int res = b;
        for(int a=1; a<=h; a++){
            if(res < n && graph[a][res]) res = res+1;
            else if(res > 1 && graph[a][res-1]) res = res-1;
        }
        if(res != b) return false;
    }

    return true;
}

void dfs(int depth, int cnt, int start){
    if(check) return;

    if(depth == cnt){
        if(traverse()) check = true;
        return;
    }

    for(int idx = start; idx < (n-1)*h; idx++){
        int a = idx/(n-1) +1;
        int b = idx%(n-1) +1;
        if(graph[a][b-1] || graph[a][b] || graph[a][b+1]) continue;

        graph[a][b] = 1;
        dfs(depth+1, cnt, idx+1);
        graph[a][b] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> h;
    graph.resize(h+1, vector<int>(n+1, 0));
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }

    check = false;
    for(int cnt=0; cnt<=3; cnt++){
        dfs(0, cnt, 0);
        if(check) {
            cout << cnt << '\n';
            return 0;
        }
    }
    cout << "-1\n";

    return 0;
}
