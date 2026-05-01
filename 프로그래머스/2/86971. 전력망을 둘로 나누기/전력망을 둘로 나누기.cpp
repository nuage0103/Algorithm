#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> parent;
vector<int> Rank;

int Find(int a){
    if(a == parent[a]) return a;
    else{
        return parent[a] = Find(parent[a]);
    }
}

void Union(int a, int b){    
    int ra = Find(a);
    int rb = Find(b);
    if(Rank[ra] < Rank[rb]) swap(ra, rb);
    
    parent[rb] = ra;
    Rank[ra] += Rank[rb];
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    parent.resize(n + 1);
    Rank.resize(n + 1);
    for(int skip = 0; skip < wires.size(); skip++){
        // 초기화
        for(int i = 1; i <= n; i++) parent[i] = i;
        fill(Rank.begin(), Rank.end(), 1);
        
        for(int i = 0; i < wires.size(); i++){
            if(i == skip) continue;  
            Union(wires[i][0], wires[i][1]);
        }
        vector<int> root;
        for(int i = 1; i <= n; i++){
            if(Find(i) == i) root.push_back(i);
        }
        answer = min(answer, abs(Rank[root[0]] - Rank[root[1]]));
    }
    
    return answer;
}