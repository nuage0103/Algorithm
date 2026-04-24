#include <string>
#include <vector>
#include <queue>

using namespace std;
/*
s 출발. a, b 모두 가는 최저 요금
1~n
무향 그래프

1. 합승해서 이동: s -> i
2. 따로 이동: i -> a = a -> i / b -> i
*/

typedef pair<int, int> pii;

vector<vector<pii>> adj;

void di(int st, vector<int>& dist){
    dist[st] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q; // {dist, node}
    q.push({dist[st], st});
    while(!q.empty()){
        int x = q.top().second;
        int d = q.top().first;
        q.pop();
        
        if(d != dist[x]) continue;
        
        for(auto& p: adj[x]){
            int nx = p.first;
            int w = p.second;
            if(dist[nx] == -1 || dist[nx] > d + w){
                dist[nx] = d + w;
                q.push({d + w, nx});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    adj.assign(n + 1, vector<pii>());
    for(int i = 0; i < fares.size(); i++){
        int u = fares[i][0], v = fares[i][1];
        int w = fares[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<int> dist_s(n + 1, -1);
    vector<int> dist_a(n + 1, -1);
    vector<int> dist_b(n + 1, -1);
    di(s, dist_s);
    di(a, dist_a);
    di(b, dist_b);
    
    answer = 1e9;
    for(int i = 1; i <= n; i++){
        if(dist_s[i] == -1 || dist_a[i] == -1 || dist_b[i] == -1) continue;
        // s->i 까지 합승
        answer = min(answer, dist_s[i] + dist_a[i] + dist_b[i]);
    }
    
    return answer;
}