#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> time(n);
    for(int i=0; i<n; i++){
        cin >> time[i];
    }

    sort(time.begin(), time.end());
    ll min_time = LONG_LONG_MAX;
    ll st = 1;
    ll en = time[0]*m; // 시간
    // 시간t 동안 각 심사대에서 t/time[i] 만큼의 인원 처리 가능
    // 처리가능한 인원수의 합 >= m
    while(st <= en){
        ll mid = (st+en)/2;
        ll cnt = 0;
        for(int i=0; i<n; i++){
            cnt += (mid/time[i]);
        }

        if(cnt >= m){
            min_time = min(min_time, mid);
            en = mid-1;
        }
        else st = mid+1;
    }

    cout << min_time << '\n';

    return 0;
}
