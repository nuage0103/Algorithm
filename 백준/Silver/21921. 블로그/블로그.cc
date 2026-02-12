#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> inp(n);
    for(int i=0; i<n; i++){
        cin >> inp[i];
    }

    int max_sum = 0;
    int cnt = 1;
    for(int i=0; i<x; i++){
        max_sum += inp[i];
    }

    int sum = max_sum;
    for(int i=0; i<n-x; i++){
        sum -= inp[i];
        sum += inp[i+x];
        if(max_sum == sum) cnt++;
        else if(max_sum < sum){
            max_sum = sum;
            cnt = 1;
        }
    }

    if(max_sum) cout << max_sum << '\n' << cnt << '\n';
    else cout << "SAD\n";

    return 0;
}
