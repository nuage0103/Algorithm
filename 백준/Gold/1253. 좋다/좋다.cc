#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int res = 0;
    for(int i=0; i<n; i++){
        int val = a[i];

        int l = 0, r = n-1;
        while(l < r){
            int sum = a[l] + a[r];
            if(sum == val){
                if(l != i && r != i) {
                    res++;
                    break;
                }
                else if(l == i) l++;
                else if(r == i) r--;
            }
            else if(sum < val) l++;
            else r--;
        }
    }
    cout << res << '\n';

    return 0;
}
