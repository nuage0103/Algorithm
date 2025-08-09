#define _CRT_SECURE_NO_WARNINGS
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    int prime[101]; // <= 541 prime
    priority_queue<long long, vector<long long>, greater<long long>> q; // min heap
    for (int i = 0; i < k; i++) {
        scanf("%d", &prime[i]);
        q.push(prime[i]);
    }

    // root로 생성 가능한 결과 : root 이루는 소인수 이하의 수만 곱셈, 푸시
    // 모두 생성한 후 팝, cnt + 1
    int cnt = 0;
    long long cur = 0;
    while (cnt < n) {
        cur = q.top();

        for (int i = 0; i < k; i++) {
            // 정답 2^31 미만 자연수
            if (cur * prime[i] > INT_MAX) {
                break;
            }

            int next = cur * prime[i];
            q.push(next);
            if (cur % prime[i] == 0) {
                break;
            }
        }

        q.pop();
        cnt++;
    }

    printf("%lld\n", cur);

    return 0;
}
