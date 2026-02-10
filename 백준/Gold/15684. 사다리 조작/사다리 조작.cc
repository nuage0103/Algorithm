#include<bits/stdc++.h>
using namespace std;

int n, m, h;
vector<vector<int>> graph;
bool check;

int traverse(int y){
    for(int x=1; x<=h; x++){
        if(y < n && graph[x][y]) y = y+1;
        else if(y > 1 && graph[x][y-1]) y = y-1;
    }

    return y;
}

void dfs(int depth, int cnt){
    if(check) return;

    if(depth == cnt){
        for(int b=1; b<=n; b++){
            if(traverse(b) != b) return;
        }
        check = true;
        return;
    }

    for(int b=1; b<n; b++){
        for(int a=1; a<=h; a++){
            if(graph[a][b-1] || graph[a][b] || graph[a][b+1]) continue;

            graph[a][b] = 1;
            dfs(depth+1, cnt);
            graph[a][b] = 0;
        }
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
        dfs(0, cnt);
        if(check) {
            cout << cnt << '\n';
            return 0;
        }
    }
    cout << "-1\n";

    return 0;
}
