#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

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

    sort(h.begin(), h.end());

    ll min_diff = 1e10;
    for(int st1=0; st1<n-1; st1++){
        for(int en1=st1+1; en1<n; en1++){
            int sum1 = h[st1] + h[en1];

            int st2=0, en2=n-1;
            while(st2==st1 || st2==en1) st2++;
            while(en2==st1 || en2==en1) en2--;

            while(st2 < en2){
                int sum2 = h[st2] + h[en2];
                ll diff = sum1 - sum2;

                min_diff = min(min_diff, abs(diff));
                if(min_diff == 0) break;

                if(diff < 0){ // sum1 < sum2
                    en2--;
                    while(en2==st1 || en2==en1) en2--;
                }
                else{ // sum1 > sum2
                    st2++;
                    while(st2==st1 || st2==en1) st2++;
                }
            }
            if(min_diff == 0) break;
        }
        if(min_diff == 0) break;
    }

    cout << min_diff << '\n';

    return 0;
}
