#include<bits/stdc++.h>
using namespace std;

vector<int> inp;
vector<int> idx_tree;
int leaf;

void make_tree(int n){
    leaf = 1;
    while(leaf < n) leaf *= 2;
    idx_tree.resize(leaf * 2);

    for(int i = 0; i < n; i++){
        int idx = leaf + i;
        idx_tree[idx] = inp[i];

        idx /= 2;
        while(idx){
            idx_tree[idx] = idx_tree[idx * 2] + idx_tree[idx * 2 + 1];
            idx /= 2;
        }
    }
}

int query(int st, int en){
    st = leaf + (st - 1);
    en = leaf + (en - 1);

    int sum = 0;
    while(st <= en){
        if(st % 2 == 1){
            sum += idx_tree[st];
            st++;
        }
        if(en % 2 == 0){
            sum += idx_tree[en];
            en--;
        }

        st /= 2;
        en /= 2;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    inp.resize(n);
    for(int i = 0; i < n; i++){
        cin >> inp[i];
    }

    make_tree(n);

    cin >> m;
    while(m--){
        int i, j;
        cin >> i >> j;
        cout << query(i, j) << '\n';
    }

    return 0;
}
