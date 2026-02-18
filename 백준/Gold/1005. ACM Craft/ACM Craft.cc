#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k, w;
        cin >> n >> k;
        vector<int> d(n+1);
        vector<vector<int>> graph(n+1);
        vector<int> indegree(n+1);
        for(int i=1; i<=n; i++){
            cin >> d[i];
        }
        for(int i=0; i<k; i++){
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            indegree[y]++;
        }
        cin >> w;

        queue<pair<int, int>> q;
        vector<int> res(n+1);
        for(int i=1; i<=n; i++){
            if(!indegree[i]) {
                q.push({i, d[i]});
                res[i] = d[i];
            }
        }

        bool flag = false;
        while(!q.empty() && !flag){
            int u = q.front().first;
            int t = q.front().second;
            q.pop();

            for(int i=0; i<graph[u].size(); i++){
                int v = graph[u][i];
                indegree[v]--;
                res[v] = max(res[v], t+d[v]);

                if(!indegree[v]) {
                    q.push({v, res[v]});
                    if(v == w) {
                        flag = true;
                        break;
                    }
                }
            }
        }

        cout << res[w] << '\n';
    }

    return 0;
}
