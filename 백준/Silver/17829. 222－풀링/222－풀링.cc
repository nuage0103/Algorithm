#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

int pool(int n, int r, int c){
    if(n == 1){
        // 풀링 못함. 입력값 그대로 반환
        return graph[r][c];
    }

    vector<int> p(4);
    n /= 2;
    p[0] = pool(n, r, c);
    p[1] = pool(n, r, c + n);
    p[2] = pool(n, r + n, c);
    p[3] = pool(n, r + n, c + n);

    sort(p.begin(), p.end());
    return p[2];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    graph.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    cout << pool(n, 0, 0) << '\n';

    return 0;
}
