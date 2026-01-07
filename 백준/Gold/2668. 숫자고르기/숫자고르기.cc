#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> num; // 1~n
vector<int> visited;
vector<int> in_cycle;
vector<int> ans;

// idx -> num[idx] = idx' -> num[idx'] ->...
void dfs(int idx){
    visited[idx] = 1;
    int x = num[idx];

    if(!visited[x]) {
       dfs(x);
    }
    else if(!in_cycle[x]){ // 재방문(사이클 형성), 아직 사이클 여부 표시안함
        // x = num[idx]
        // x -> num[x] -> ... -> idx -> x = num[idx]
        // 사이클 원소 모두 ans에 추가
        while(1){
            ans.push_back(x);
            if(x == idx) break;
            x = num[x];
        }
    }

    // dfs 스택에 있는 사이클 원소들 순서대로 표시
    in_cycle[idx] = 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    num.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }

    visited.resize(n + 1);
    in_cycle.resize(n + 1);
    for(int i = 1; i <= n; i++){
        if(!visited[i]) dfs(i);
    }

    sort(ans.begin(), ans.end());
    int cnt = ans.size();
    cout << cnt << '\n';
    for(int i = 0; i < cnt; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}
