#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int freq[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int st = 0, en = 0;
    int res = -1;
    while(st < n && st <= en){
        while(en < n && freq[a[en]] < k) {
            freq[a[en]]++;
            en++;
        }

        res = max(res, en - st);
        freq[a[st]]--;
        st++;
    }
    cout << res << '\n';

    return 0;
}
