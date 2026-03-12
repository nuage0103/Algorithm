#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
int n;
vector<ll> a;
vector<ll> dp;

ll solve(int x){ // x ~ n-1 경로 최소값
    if(x == n-1) return 0;
    if(dp[x] != -1) return dp[x];

    ll& res = dp[x];
    // 전체 경로 비용 = 해당 경로의 최대값
    // 모든 경로에 대해 최소값
    // 답: dp[n-1] = 최소값
    // dp[i] = a[i]까지 도달하는데 최소값
    res = 1e10;
    for(int i = x + 1; i < n; i++){
        ll power = (i - x) * (1 + abs(a[i] - a[x]));
        res = min(res, max(solve(i), power));
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    dp.resize(n, -1);
    cout << solve(0) << '\n'; // 0 ~ n-1 경로 최소값

    return 0;
}
