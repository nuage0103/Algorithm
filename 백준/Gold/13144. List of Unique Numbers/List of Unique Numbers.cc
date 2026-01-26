#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> inp(n);
    for(int i=0; i<n; i++){
        cin >> inp[i];
    }

    long long res = 0;
    int st = 0, en = 0;
    vector<int> visited(100001);
    visited[inp[st]] = 1;
    while(st < n){
        while(en < n-1 && visited[inp[en+1]] == 0){
            en++;
            visited[inp[en]]++;
        }

        res += (en - st + 1);
        visited[inp[st]]--;
        st++;
    }

    cout << res << '\n';

    return 0;
}
