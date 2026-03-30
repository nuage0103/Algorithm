#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> cap(n);
    for(int i = 0; i < n; i++){
        cin >> cap[i];
    }

    int st = 0, en = n - 1;
    int cnt = n - 2;
    int res = -1;
    while(st <= en){
        res = max(res, cnt * min(cap[st], cap[en]));

        if(cap[st] < cap[en]) st++;
        else en--;
        cnt--;
    }

    cout << res << '\n';

    return 0;
}
