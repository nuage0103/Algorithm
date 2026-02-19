#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, total;
    cin >> n;
    vector<int> req(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> req[i];
        sum += req[i];
    }
    cin >> total;
    sort(req.begin(), req.end());

    if(sum <= total){
        cout << req[n-1] << '\n';
        return 0;
    }

    int st = req[0], en = req[n-1];
    int res = total / n;
    while(st <= en){
        int mid = (st + en) / 2;
        int tmp = mid * n;
        for(int x: req){
            if(x < mid) {
                tmp -= mid;
                tmp += x;
            }
            else break;
        }

        if(tmp <= total){
            res = max(res, mid);
            st = mid + 1;
        }
        else {
            en = mid - 1;
        }
    }
    cout << res << '\n';

    return 0;
}
