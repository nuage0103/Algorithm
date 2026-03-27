#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    unordered_map<string, int> title;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        title[s]++;
    }

    vector<pair<string, int>> res(title.begin(), title.end());
    sort(res.begin(), res.end(), [](const auto &a, const auto &b){
        if(a.second != b.second) return a.second > b.second;
        else return a.first < b.first;
    });

    cout << res[0].first << '\n';

    return 0;
}
