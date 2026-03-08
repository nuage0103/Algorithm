#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    // 누적합 (0, 0) ~ (x, y)
    vector<vector<int>> sum(n, vector<int>(m));
    sum[0][0] = graph[0][0];
    for(int j = 1; j < m; j++) sum[0][j] = sum[0][j-1] + graph[0][j];
    for(int i = 1; i < n; i++) sum[i][0] = sum[i-1][0] + graph[i][0];
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] + graph[i][j] - sum[i-1][j-1];
        }
    }

    int res = INT_MIN;
    for(int sx = 0; sx < n; sx++){
        for(int sy = 0; sy < m; sy++){
            for(int ex = sx; ex < n; ex++){
                for(int ey = sy; ey < m; ey++){
                    int cur = sum[ex][ey];
                    if(sx > 0) cur -= sum[sx - 1][ey];
                    if(sy > 0) cur -= sum[ex][sy - 1];
                    if(sx > 0 && sy > 0) cur += sum[sx - 1][sy - 1];
                    res = max(res, cur);
                }
            }
        }
    }
    cout << res << '\n';

    return 0;
}
