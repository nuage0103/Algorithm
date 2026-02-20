#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> graph(n+1);
    vector<int> indegree(n+1);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        indegree[y]++;
    }

    // indegree[x]: x가 만족해야 하는 선행조건 개수
    // indegree[x] = 0: x에 대한 선행조건 없음
    // u 건설: indegree[v]--
    // u 파괴: indegree[v]++
    vector<int> freq(n+1);
    bool cheat = false;
    while(k--){
        int type, a;
        cin >> type >> a;

        if(cheat) continue;

        if(type == 1){
            // 건설
            if(indegree[a]){
                cheat = true;
            }
            else{
                freq[a]++;
                if(freq[a] >= 2) continue;

                // 건물 하나
                for(int v: graph[a]){
                    indegree[v]--;
                }
            }
        }
        else{
            // 파괴
            if(!freq[a]) {
                cheat = true;
            }
            else{
                freq[a]--;
                if(freq[a]) continue;

                // 건물 없음
                for(int v: graph[a]){
                    indegree[v]++;
                }
            }
        }
    }

    if(cheat) cout << "Lier!\n";
    else cout << "King-God-Emperor\n";

    return 0;
}
