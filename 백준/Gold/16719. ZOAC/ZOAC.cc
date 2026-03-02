#include<bits/stdc++.h>
using namespace std;

string s;
int len;
vector<int> used;

void solve(int l, int r){
    char min_c = 'Z' + 1;
    int idx = -1;
    for(int i = l; i <= r; i++){
        if(used[i]) continue;

        if(min_c > s[i]){
            min_c = s[i];
            idx = i;
        }
    }

    if(idx == -1) return;

    used[idx] = 1;
    for(int i = 0; i < len; i++){
        if(used[i]) cout << s[i];
    }
    cout << '\n';

    // 규칙: 추가했을 때 전체 문자열이 사전순으로 가장 앞에 오도록
    solve(idx + 1, r); // idx 이후(오른쪽) 먼저 탐색
    solve(l, idx - 1); // idx보다 이전 문자를 결과 문자열에 삽입하면 사전순으로 가장 앞설 수 없음. idx 이전 문자들은 모두 사전순으로 idx보다 뒤
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    len = s.size();
    used.resize(len);

    solve(0, len - 1);

    return 0;
}
