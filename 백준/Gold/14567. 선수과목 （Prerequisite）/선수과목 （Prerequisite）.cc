#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> indegree(n+1);
    while(m--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    vector<int> res(n+1);
    for(int i = 1; i <= n; i++){
        if(!indegree[i]) {
            q.push(i);
            res[i] = 1;
        }
    }
    while(!q.empty()){
        int u = q.front();
        int w = res[u];
        q.pop();

        for(int v: graph[u]){
            if(res[v]) continue;

            indegree[v]--;
            if(!indegree[v]){
                res[v] = w + 1;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}
