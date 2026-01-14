#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> inp(n);
    for(int i=0; i<n; i++){
        cin >> inp[i];
    }

    int res = 0;
    vector<int> freq(100001, 0);
    int end = 0;
    for(int start = 0; start<n; start++){
        while(end < n && freq[inp[end]] < k){
            freq[inp[end]]++;
            end++;
        }
        res = max(res, end - start);

        if(end == n) break;
        freq[inp[start]]--;
    }

    cout << res << '\n';

    return 0;
}
