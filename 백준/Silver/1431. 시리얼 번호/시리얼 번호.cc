#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<string, int>> inp;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int sum = 0;
        for(int j = 0; j < s.length(); j++){
            if(s[j] >= '0' && s[j] <= '9') sum += s[j] - '0';
        }
        inp.push_back({s, sum});
    }

    sort(inp.begin(), inp.end(), [](const auto& a, const auto& b){
        // 짧
        if(a.first.length() != b.first.length()) return a.first.length() < b.first.length();
        // 합 작
        else if(a.second != b.second) return a.second < b.second;
        // 사전순
        else return a.first < b.first;
    });

    for(auto x: inp) cout << x.first << '\n';

    return 0;
}
