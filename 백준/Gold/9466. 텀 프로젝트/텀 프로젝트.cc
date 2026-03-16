#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt;
vector<int> graph;
vector<int> visited, done;

/*
사이클 찾기

무방향 그래프: 서로소 집합(Union - Find)
방향 그래프:
- DFS & 재귀 스택
- visited 배열(방문 여부 확인) & done 배열(사이클 여부 확인)

- 현재 노드에 대해 visited, done에 표시
- 현재 노드와 인접한 노드 중 방문하지 않은 노드에 대해 dfs 재귀호출
- 인접 노드가 이미 done 참이면 사이클 있다고 판단
*/

void dfs(int x){
    visited[x] = 1;
    int nx = graph[x];

    if(!visited[nx]) dfs(nx);
    else if(!done[nx]){
        // 이미 방문함. 사이클 처리 필요
        for(int cur = nx; cur != x; cur = graph[cur]) cnt++;
        cnt++; // x까지 포함
    }

    done[x] = 1; // dfs 종료
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n;

        graph.clear();
        graph.resize(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> graph[i];
        }

        visited.clear();
        done.clear();
        visited.resize(n + 1);
        done.resize(n + 1);
        cnt = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[i]) dfs(i);
        }

        cout << n - cnt << '\n';
    }

    return 0;
}
