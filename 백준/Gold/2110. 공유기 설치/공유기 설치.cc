#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, c;
    cin >> n >> c;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    if(c == 2){
        cout << x[n - 1] - x[0] << '\n';
        return 0;
    }

    int min_len = 0;
    int st = 0, en = x[n- 1] - x[0];
    while(st <= en){
        int mid = (st + en) / 2; // 거리
        int cnt = 1; // 설치 개수
        int p = 0, np = 1;
        while(np < n){
            if(x[np] - x[p] >= mid){
                p = np;
                np = p + 1;
                cnt++;
                continue;
            }
            np++;
        }

        if(cnt >= c){
            min_len = max(min_len, mid);
            st = mid + 1;
        }
        else{
            en = mid - 1;
        }
    }
    cout << min_len << '\n';

    return 0;
}
