#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> order(n); // 입력된 팀번호 순서대로 저장
        unordered_map<int, int> team_freq; // {팀번호, 개수}
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            order[i] = x;
            if(team_freq.find(x) == team_freq.end()) team_freq[x] = 1;
            else team_freq[x]++;
        }

        int cur = 1; // order 순서대로 점수 부여
        unordered_map<int, vector<int>> info; // {팀번호, 점수 벡터}
        for(int i=0; i<n; i++){
            if(team_freq[order[i]] < 6) continue;

            info[order[i]].push_back(cur);
            cur++;
        }

        // 우승팀 결정
        int min_score = 10000;
        int winner = 0;
        for(auto& it: info){
            int score = 0; // 팀 내 1~4등 점수 합산
            int team = it.first;
            for(int i=0; i<4; i++){
                score += it.second[i];
            }

            // 점수 낮을수록 우승
            if(min_score > score) {
                min_score = score;
                winner = team;
            }
            else if(min_score == score){
                // 5등 점수 비교
                if(it.second[4] < info[winner][4]){
                    winner = team;
                }
            }
        }

        cout << winner << '\n';
    }

    return 0;
}
