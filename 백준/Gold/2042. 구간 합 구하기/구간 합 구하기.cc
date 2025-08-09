#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

long long arr[1000001];
vector<long long> idxtree;
int leaf;

void update(int idx, long long val) {
    idx += leaf;
    idxtree[idx] = val;

    while (idx > 1) {
        idx /= 2;
        idxtree[idx] = idxtree[idx * 2] + idxtree[idx * 2 + 1];
    }
}

long long query(int start, int end) {
    long long sum = 0;

    start += leaf;
    end += leaf;
    while (start <= end) {
        if (start % 2 == 1) {
            // right child
            sum += idxtree[start];
        }
        if (end % 2 == 0) {
            // left child
            sum += idxtree[end];
        }

        // parent로 이동
        start = (start + 1) / 2;
        end = (end - 1) / 2;
    }

    return sum;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    // tree 초기화
    leaf = 1;
    while (leaf < n) {
        leaf *= 2;
    }
    idxtree.resize(leaf * 2, 0);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        idxtree[leaf + i] = arr[i];
    }

    for (int i = leaf - 1; i >= 1; i--) {
        idxtree[i] = idxtree[i * 2] + idxtree[i * 2 + 1];
    }

    // 업데이트, 구간합
    for (int i = 0; i < m + k; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        if (a == 1) {
            update(b - 1, c);
        } else if (a == 2) {
            printf("%lld\n", query(b - 1, c - 1));
        }
    }

    return 0;
}
