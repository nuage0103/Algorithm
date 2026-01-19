#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> have;

int check(int target){
    int st = 0;
    int en = n-1;
    while(st <= en){
        int mid = (st+en)/2;
        if(have[mid] == target) return 1;
        else if(have[mid] < target) st = mid+1;
        else en = mid-1;
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    have.resize(n);
    for(int i=0; i<n; i++){
        cin >> have[i];
    }
    sort(have.begin(), have.end());

    int m;
    cin >> m;
    vector<int> find(m);
    vector<int> res(m, 0);
    for(int i=0; i<m; i++){
        cin >> find[i];
        res[i] = check(find[i]);
    }

    for(auto x: res) cout << x << ' ';
    cout << '\n';

    return 0;
}
