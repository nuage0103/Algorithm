#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> num(n); // 1~9
    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    int max_sum = -1;
    int st = 0, en = 0;
    vector<int> freq(10);
    int cnt = 0;
    while(en < n){
        if(!freq[num[en]]) cnt++;
        freq[num[en]]++;

        while(cnt > 2) {
            freq[num[st]]--;
            if(!freq[num[st]]) cnt--;
            st++;
        }

        max_sum = max(max_sum, en-st+1);
        en++;
    }

    cout << max_sum << '\n';

    return 0;
}
