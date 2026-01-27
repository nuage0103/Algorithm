#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin >> h[i];
    }

    vector<int> see(n);
    for(int i=0; i<n-1; i++){
        double max_tan = -1e63;
        for(int j=i+1; j<n; j++){
            double tan = (h[j]-h[i])/((double)j-i);
            if(tan > max_tan){
                max_tan = tan;
                see[i]++;
                see[j]++;
            }
        }
    }

    int res = 0;
    for(int i=0; i<n; i++){
        res = max(res, see[i]);
    }
    cout << res << '\n';

    return 0;
}
