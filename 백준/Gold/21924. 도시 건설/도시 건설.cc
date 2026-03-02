#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> parent;

int Find(int a){
    if(parent[a] == a) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
    int ra = Find(a);
    int rb = Find(b);

    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> graph; // {w, {u, v}}
    ll sum = 0;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({w, {u, v}});
        sum += w;
    }

    parent.resize(n + 1);
    for(int i = 1; i <= n; i++) parent[i] = i;

    sort(graph.begin(), graph.end());
    ll res = 0;
    int e_cnt = 0;
    for(int i = 0; i < graph.size(); i++){
        int u = graph[i].second.first;
        int v = graph[i].second.second;
        int w = graph[i].first;

        if(Find(u) == Find(v)) continue;

        res +=w;
        e_cnt++;
        Union(u, v);

        if(e_cnt == n - 1) break;
    }

    if(e_cnt != n - 1) cout << "-1\n";
    else cout << sum - res << '\n';

    return 0;
}
