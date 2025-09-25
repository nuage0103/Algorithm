#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 연속된 소수의 합, 각 소수는 한번만 사용
	int n;
	cin >> n;

	if (n == 1) {
		cout << "0\n";
		return 0;
	}

	vector<int> is_prime(n + 1); // 소수 맞음0, 아님1
	is_prime[0] = 1;
	is_prime[1] = 1;
	for (int i = 2; i <= sqrt(n); i++) {
		if (is_prime[i] == 0) {
			// i*(i-1)까지는 이미 기존에 확인
			// sqrt(n)인 경우 sqrt(n)*sqrt(n)부터 확인
			// sqrt(n)*sqrt(n)=n이니까 그 이상의 i에 대해 검사할 필요 없음
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = 1;
			}
		}
	}

	vector<int> prime;
;	for (int i = 2; i <= n; i++) {
		if (!is_prime[i]) prime.push_back(i);
	}

	int start = 0;
	int end = 0;
	int sum = prime[start];
	int cnt = 0;	
	while (start <= end) {
		if (sum < n) {
			end++;
			if (end == prime.size()) break;
			sum += prime[end];
		}
		else {
			if (sum == n) cnt++;
			sum -= prime[start];
			start++;
		}
	}

	cout << cnt << '\n';
	
	return 0;
}