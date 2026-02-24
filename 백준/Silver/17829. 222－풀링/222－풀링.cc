#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

int pool(int r, int c){
    vector<int> p;
    for(int i = r; i < r + 2; i++){
        for(int j = c; j < c + 2; j++){
            p.push_back(graph[i][j]);
        }
    }
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

    while(n){
        for(int i = 0; i < n; i += 2){
            for(int j = 0; j < n; j += 2){
                graph[i/2][j/2] = pool(i, j);
            }
        }

        n /= 2;
    }
    cout << graph[0][0] << '\n';

    return 0;
}
