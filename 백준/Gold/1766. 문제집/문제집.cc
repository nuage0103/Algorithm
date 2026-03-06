#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1);
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> q; // min heap
    for(int i = 1; i <= n; i++){
        if(!indegree[i]) q.push(i);
    }
    while(!q.empty()){
        int x = q.top();
        q.pop();
        res.push_back(x);

        for(int i = 0; i < adj[x].size(); i++){
            int nx = adj[x][i];
            indegree[nx]--;

            if(!indegree[nx]) q.push(nx);
        }
    }

    for(int x: res) cout << x << ' ';
    cout << '\n';

    return 0;
}
