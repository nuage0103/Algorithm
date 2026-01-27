#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> word(n);
    vector<pair<string, int>> word_idx(n); // {str, idx}
    for(int i=0; i<n; i++){
        cin >> word[i];
        word_idx[i] = {word[i], i};
    }
    sort(word_idx.begin(), word_idx.end(), [](auto& p1, auto& p2){
        if(p1.first != p2.first) return p1.first < p2.first;
        else return p1.second < p2.second;
    });

    int max_cnt = -1;
    map<string, vector<int>> m; // {접두사, idx 배열}
    for(int i=0; i<n-1; i++){
        int cnt = 0;
        string& s1 = word_idx[i].first;
        string& s2 = word_idx[i+1].first;

        while(1){
            if(s1.length() <= cnt || s2.length() <= cnt) break;
            if(s1[cnt] != s2[cnt]) break;
            cnt++;
        }

        int idx1 = word_idx[i].second, idx2 = word_idx[i+1].second;

        if(cnt >= max_cnt){
            if(cnt > max_cnt) max_cnt = cnt;

            string prefix = s1.substr(0, max_cnt);
            if(m.find(prefix) == m.end()){
                m[prefix].push_back(idx1);
                m[prefix].push_back(idx2);
            }
            else m[prefix].push_back(idx2);
        }
    }

    string s, t;
    int idx1 = 40000, idx2 = 40000;
    for(auto& p: m){
        if(p.first.length() < max_cnt) continue;

        sort(p.second.begin(), p.second.end());
        int tmp1 = p.second[0], tmp2 = p.second[1];
        if(tmp1 < idx1) {
            idx1 = tmp1;
            idx2 = tmp2;
        }
    }

    cout << word[idx1] << '\n' << word[idx2] << '\n';

    return 0;
}
