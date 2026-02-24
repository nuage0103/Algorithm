#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1e6 + 1
vector<int> parent(MAX_SIZE);
vector<int> freq(MAX_SIZE, 1);

int Find(int a){
    if(a == parent[a]) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
    int root_a = Find(a);
    int root_b = Find(b);

    parent[root_b] = root_a;
    freq[root_a] += freq[root_b];
    freq[root_b] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i < MAX_SIZE; i++) parent[i] = i;
    while(n--){
        char c;
        cin >> c;

        if(c == 'I'){
            int a, b;
            cin >> a >> b;

            if(a > b) swap(a, b);
            // a < b
            if(Find(a) != Find(b)) Union(a, b);
        }
        else{
            int a;
            cin >> a;
            int root_a = Find(a);
            cout << freq[root_a] << '\n';
        }
    }

    return 0;
}
