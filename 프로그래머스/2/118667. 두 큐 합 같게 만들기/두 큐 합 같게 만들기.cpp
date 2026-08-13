#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    ll total1 = 0, total2 = 0;
    vector<int> q;
    int n = queue1.size();
    for(int i = 0; i < n; i++){
        total1 += queue1[i];
        q.push_back(queue1[i]);
    }
    for(int i = 0; i < n; i++){
        total2 += queue2[i];
        q.push_back(queue2[i]);
    }
    
    if((total1 + total2) % 2 == 1) return -1;
    if(total1 == total2) return 0;
    
    int st = 0, en = n - 1;
    answer = 0;
    n = q.size();
    while(answer < 3 * n){
        if(total1 == total2) return answer;
        
        if(total1 > total2){
            total1 -= q[st];
            total2 += q[st];
            st = (st + 1) % n;
        }
        else{
            en = (en + 1) % n;
            total1 += q[en];
            total2 -= q[en];
        }
        answer++;
    }
    
    return -1;
}