#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> folder; // {이름, 고유번호}
vector<int> is_dir(2001); // [고유번호] = 폴더 1 / 파일 0
vector<vector<int>> graph(2001); // [고유번호]의 하위 폴더, 파일

int dfs(int cur, unordered_set<int>& kind){
    int cnt = 0;

    for(auto next: graph[cur]){
        if(!is_dir[next]){ // 파일
            cnt++;
            kind.insert(next);
        }
        else{ // 폴더
            cnt += dfs(next, kind);
        }
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int t = n + m;

    int cnt = 0; // 고유번호
    while(t--){
        string parent, child;
        int dir; // 1: 폴더, 0: 파일
        cin >> parent >> child >> dir;

        // 고유번호 부여
        if(folder.find(parent) == folder.end()){
            folder[parent] = cnt;
            cnt++;
        }
        if(folder.find(child) == folder.end()){
            folder[child] = cnt;
            cnt++;
        }
        // 인접트리 생성
        graph[folder[parent]].push_back(folder[child]);
        // 폴더, 파일 종류
        is_dir[folder[parent]] = 1;
        is_dir[folder[child]] = dir;
    }

    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;

        int pos = -1;
        int prev = 0;
        while(1){
            pos = s.find('/', prev);
            if(pos == string::npos) break;
            prev = pos + 1;
        }
        string tmp = s.substr(prev);
        // 파일 종류 개수(중복 제거), 총 개수
        int start = folder[tmp];
        unordered_set<int> us;
        int total = dfs(start, us);
        cout << us.size() << ' ' << total << '\n';
    }

    return 0;
}
