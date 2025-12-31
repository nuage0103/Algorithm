#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
stack
#include <stack>
라기보다는 LIFO 동작에 초점
- 문자열의 마지막 문자 = top: push_back(char), append(str) / pop_back(char), pop(str)
- 배열을 스택처럼 사용: append(), pop()
- 인덱스로 top 관리, 명시적인 pop() 사용하지는 않음
arr = []
top = -1
top++(push) / top--(pop)
*/

/*
출발 1 -> 도착 100. 주사위 최소 횟수
주사위 x: 현재 + x로 이동
사다리 현재+ / 뱀 현재-
*/

typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int map[101] = {0}; // map[u] = v(뱀 / 사다리). map[u] = 0(주사위 이동으로 끝)
    int u, v; // != 1, 100
    for(int i = 0; i < n; i++){
        cin >> u >> v;
        map[u] = v;
    }
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        map[u] = v;
    }

    queue<pii> q; // {cur, move}
    int visited[101] = {0};
    q.push({1, 0});
    while(!q.empty()){
        pii p = q.front();
        int cur = p.first;
        int move = p.second;
        q.pop();

        for(int i = 1; i <= 6; i++){
            // 주사위
            int next = cur + i;
            if(next > 100) continue;
            if(next == 100){
                cout << move + 1 << '\n';
                return 0;
            }

            // 뱀, 사다리
            while(map[next]){
                next = map[next];
            }

            // 이동
            if(!visited[next]){
                visited[next] = 1;
                q.push({next, move + 1});
            }
        }
    }

    return 0;
}
