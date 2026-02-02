#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int d = pow(x1-x2, 2) + pow(y1-y2, 2);
        int diff = pow(r1-r2, 2), sum = pow(r1+r2, 2);

        if(d == 0){
            if(diff == 0) cout << "-1\n";
            else cout << "0\n";
        }
        else if(d > diff && d < sum) cout << "2\n";
        else if (d == diff || d == sum) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}
