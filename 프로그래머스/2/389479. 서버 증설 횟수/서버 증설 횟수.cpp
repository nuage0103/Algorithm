#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;

    int cur = 0;
    deque<pair<int, int>> server;
    for(int i = 0; i < 24; i++){
        while(!server.empty()){
            if(server.front().second == i) {
                cur -= server.front().first;
                server.pop_front();
            }
            if(server.front().second > i) break;
        }
        
        int n = players[i] / m;
        if(cur < n){
            answer += (n - cur);
            server.push_back({n - cur, i + k});
            cur = n;
        }
    }
    return answer;
}