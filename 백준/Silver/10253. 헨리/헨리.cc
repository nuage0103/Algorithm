#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    while(b){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int a, b; // 분자, 분모. 서로소
        cin >> a >> b;

        while(1){
            if(a == 1) break;

            // 최대 단위분수 1/x. x 최소값
            int x = (b / a) + 1;
            a = a * x - b;
            b *= x;
            int g = gcd(a, b);
            a /= g, b /= g;
        }
        cout << b << '\n';
    }

    return 0;
}
