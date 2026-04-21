#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
최소 비용, 모든 섬 간에 통행: mst
costs[i] = {u, v, w}
무방향 그래프
*/

vector<int> parent;
vector<int> Rank;

int Find(int a){
    if(a == parent[a]) return a;
    else{
        parent[a] = Find(parent[a]);
        return parent[a];
    }
}

void Union(int a, int b){
    if(a == b) return;
    
    int ra = Find(a);
    int rb = Find(b);
    
    if(Rank[ra] < Rank[rb]) swap(ra, rb);
    
    parent[rb] = ra;
    Rank[ra] += Rank[rb];
}

int solution(int n, vector<vector<int>> costs) { 
    parent.resize(n);
    for(int i = 0; i < n; i++) parent[i] = i;
    Rank.resize(n, 1);
    
    sort(costs.begin(), costs.end(), [](auto& a, auto& b){
        return a[2] < b[2];
    });
    
    int answer = 0; // min weight
    int edge = 0; // edge cnt
    for(int i = 0; i < costs.size(); i++){
        int u = costs[i][0];
        int v = costs[i][1];
        int w = costs[i][2];
        
        if(Find(u) == Find(v)) continue; // cycle
        
        Union(u, v);
        answer += w;
        edge++;
        if(edge == n - 1) break;
    }
    
    return answer;
}