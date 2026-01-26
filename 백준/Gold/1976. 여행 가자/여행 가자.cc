#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int a){
    if(parent[a] == a) return a;
    else {
        return parent[a] = find(parent[a]);
    }
}

void Union(int a, int b){
    int a_root = find(a);
    int b_root = find(b);

    if(a_root < b_root) parent[b_root] = a_root;
    else parent[a_root] = b_root;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    parent.resize(n+1);
    for(int i=1; i<=n; i++) parent[i] = i;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin >> x;
            if(x == 1 && i < j) Union(i, j);
        }
    }

    int prev;
    bool check = true;
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        if(!check) continue;

        if(i == 0) prev = find(x);
        else if(find(x) != prev) check = false;
    }

    if(check) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
