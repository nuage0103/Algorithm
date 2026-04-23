#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

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

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!indegree[i]) q.push(i);
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << ' ';

        for(int nx: adj[x]){
            indegree[nx]--;
            if(!indegree[nx]) q.push(nx);
        }
    }
    cout << '\n';

    return 0;
}
