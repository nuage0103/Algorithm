#include<bits/stdc++.h>
using namespace std;

int k, m;
vector<bool> is_prime;
vector<int> prime;
int used[10] = {0};
int res;

void find_prime(){
    int s = pow(10, k+1);
    is_prime.resize(s, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<sqrt(s)+1; i++){
        if(!is_prime[i]) continue;

        for(int j=i*i; j<s; j+=i){
            is_prime[j] = false;
        }
    }

    for(int i=2; i<s; i++){
        if(is_prime[i]) prime.push_back(i);
    }
}

bool check1(int n){
    for(int x: prime){
        if(x > n/2) break;

        int y = n - x;
        if(x != y && is_prime[y]) return true;
    }

    return false;
}

bool check2(int n){
    for(int x: prime){
        if(x > sqrt(n)) break;

        if(n % x == 0){
            int y = n / x;
            if(is_prime[y]) return true;
        }
    }

    return false;
}

void make_num(int depth, int cur){
    if(depth == k){
        if(check1(cur)){
            while(cur % m == 0) cur /= m;
            if(check2(cur)) res++;
        }
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> m;
    find_prime();

    res = 0;
    make_num(0, 0);
    cout << res << '\n';

    return 0;
}
