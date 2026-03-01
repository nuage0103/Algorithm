#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        priority_queue<ll, vector<ll>, greater<ll>> pq; // min heap
        for(int i = 0; i < n; i++){
            ll x;
            cin >> x;
            pq.push(x);
        }

        if(n == 1) {
            cout << 1 << '\n';
            continue;
        }

        /*
        a, b, c, d, e
        ans: 1, 1*(a*b), (a*b)*(a*b*c)=a2b2c, (a2b2c)*(a2b2cd)
        */
        ll res = 1;
        while(pq.size() >= 2){
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            pq.push(a * b);

            ll mul = ((a % MOD) * (b % MOD)) % MOD;
            res = (res * mul) % MOD;
        }
        cout << res << '\n';
    }

    return 0;
}
