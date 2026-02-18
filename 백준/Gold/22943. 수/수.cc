#include<bits/stdc++.h>
using namespace std;

int k, m;
vector<bool> prime;
vector<int> cand;
int used[10] = {0};

void find_prime(){
    int s = pow(10, k+1);
    prime.resize(s, true);
    prime[0] = prime[1] = false;
    for(int i=2; i<sqrt(s)+1; i++){
        if(!prime[i]) continue;

        for(int j=i*i; j<s; j+=i){
            prime[j] = false;
        }
    }
}

void make_num(int depth, int cur){
    if(depth == k){
        cand.push_back(cur);
        return;
    }

    for(int i=0; i<10; i++){
        if(depth == 0 && i == 0) continue;

        if(!used[i]){
            used[i] = 1;
            make_num(depth + 1, cur * 10 + i);
            used[i] = 0;
        }
    }
}

bool check1(int n){
    for(int i=2; i<n/2+1; i++){
        if(!prime[i]) continue;

        int x = n - i;
        if(x != i && prime[x]) return true;
    }

    return false;
}

bool check2(int n){
    for(int i=2; i<sqrt(n)+1; i++){
        if(!prime[i]) continue;

        int x = n / i;
        if(!(n % i) && prime[x]) return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> m;
    find_prime();
    make_num(0, 0);

    int res = 0;
    for(int n: cand){
        if(check1(n)){
            while(n % m == 0) n /= m;

            if(check2(n)) res++;
        }
    }
    cout << res << '\n';

    return 0;
}
