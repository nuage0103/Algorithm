#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
string res;

void com(int n, int x, int y){
    if(n == 1){
        res += graph[x][y] + '0';
        return;
    }

    int first = graph[x][y];
    bool same = true;
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(graph[i][j] != first){
                same = false;
                break;
            }
        }
    }

    if(same){
        res += first + '0';
        return;
    }

    n /= 2;
    res += '(';
    com(n, x, y);
    com(n, x, y + n);
    com(n, x + n, y);
    com(n, x + n, y + n);
    res += ')';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    graph.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < n; j++){
            graph[i][j] = tmp[j] - '0';
        }
    }

    res = "";
    com(n, 0, 0);
    cout << res << '\n';

    return 0;
}
