#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    unordered_map<string, int> word_freq;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s.length() < m) continue;

        word_freq[s]++; // 없으면 0으로 초기화
    }

    vector<pair<string, int>> res(word_freq.begin(), word_freq.end());
    sort(res.begin(), res.end(), [](const auto& a, const auto& b){
        // 빈도, 길이, 사전순
        if(a.second != b.second) return a.second > b.second;
        else if(a.first.length() != b.first.length()) return a.first.length() > b.first.length();
        else return a.first < b.first;
    });

    for(auto p: res) cout << p.first << '\n';

    return 0;
}
