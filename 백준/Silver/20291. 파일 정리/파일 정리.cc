#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    map<string, int> ex_freq; // {확장자, 개수}
    for(int i=0; i<n; i++){
        string file;
        cin >> file;

        int p = file.find('.');
        string ex = file.substr(p+1);
        if(ex_freq.find(ex) == ex_freq.end()) ex_freq[ex] = 1;
        else ex_freq[ex]++;
    }

    for(auto [ex, freq]: ex_freq) cout << ex << ' ' << freq << '\n';

    return 0;
}
