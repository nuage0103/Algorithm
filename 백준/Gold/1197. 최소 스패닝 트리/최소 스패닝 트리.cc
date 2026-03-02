#include<bits/stdc++.h>
using namespace std;
/*
spanning tree: 무향 연결 그래프. 모든 정점 잇는 트리. 사이클 없음
minimum spanning tree: spanning tree 중 가중치 합이 최소인 트리
*/

vector<int> parent;

int Find(int a){
    if(parent[a] == a) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
    int root_a = Find(a);
    int root_b = Find(b);

    if(root_a > root_b) swap(root_a, root_b);
    // root_a < root_b
    parent[root_b] = root_a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v, e;
    cin >> v >> e;
    vector<pair<int, pair<int, int>>> graph;
    for(int i = 0; i < e; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph.push_back({w, {a, b}});
    }

    parent.resize(v + 1);
    for(int i = 1; i <= v; i++) parent[i] = i;

    sort(graph.begin(), graph.end()); // 가중치 오름차순 정렬

    int min_w = 0;
    for(int i =0; i < graph.size(); i++){
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        int w = graph[i].first;

        // 사이클 생성 여부
        if(Find(a) == Find(b)) continue;

        min_w += w;
        Union(a, b);
    }

    cout << min_w << '\n';

    return 0;
}
