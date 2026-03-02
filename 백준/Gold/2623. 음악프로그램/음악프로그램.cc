#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1);
    for(int i = 0; i < m; i++){
        int cnt;
        cin >> cnt;

        int prev, x;
        cnt--;
        cin >> prev;
        while(cnt--){
            cin >> x;
            graph[prev].push_back(x);
            indegree[x]++;

            prev = x;
        }
    }

    vector<int> res;
    queue<int> q;
    for(int i = 1; i <=n; i++){
        if(!indegree[i]) {
            q.push(i);
            res.push_back(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i = 0; i < graph[x].size(); i++){
            int nx = graph[x][i];
            indegree[nx]--;
            if(!indegree[nx]){
                q.push(nx);
                res.push_back(nx);
            }
        }
    }

    if(res.size() != n) cout << "0\n";
    else{
        for(int x: res) cout << x << '\n';
    }

    return 0;
}
