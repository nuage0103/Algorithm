#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k, n;
    cin >> k >> n;
    vector<int> lan(k);
    for(int i=0; i<k; i++){
        cin >> lan[i];
    }
    // n개 이상의 정수 길이로 자르기, 붙이는건 없음 k<=n
    sort(lan.begin(), lan.end());
    ll max_len = 0;
    ll st = 1;
    ll en = lan[k-1]; // 길이
    while(st <= en){
        ll mid = (st+en)/2;
        ll cnt = 0;
        for(int i=0; i<k; i++){
            cnt += (lan[i]/mid);
        }

        if(cnt >= n) {
            max_len = max(max_len, mid);
            st = mid+1;
        }
        else en = mid-1;
    }

    cout << max_len << '\n';

    return 0;
}
