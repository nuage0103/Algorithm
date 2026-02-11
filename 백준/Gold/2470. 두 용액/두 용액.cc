#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> inp(n);
    for(int i=0; i<n; i++){
        cin >> inp[i];
    }

    sort(inp.begin(), inp.end());

    int st=0, en=n-1;
    long long res = 1e10;
    pair<int, int> ans;
    while(st < en){
        long long cur = inp[st] + inp[en];

        if(cur == 0) {
            ans = {st, en};
            break;
        }
        else if(cur > 0){
            if(abs(res) > abs(cur)){
                res = cur;
                ans = {st, en};
            }
            cur -= inp[en];
            en--;
        }
        else{
            if(abs(res) > abs(cur)){
                res = cur;
                ans = {st, en};
            }
            cur -= inp[st];
            st++;
        }
    }

    cout << inp[ans.first] << ' ' << inp[ans.second] << '\n';

    return 0;
}
