#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int is_prime[1000001] = { 0 }; // prime 0, not 1
vector<int> prime;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 소수 판정
	is_prime[0] = 1;
	is_prime[1] = 1;
	for (int i = 2; i <= sqrt(1000000); i++) {
		if (is_prime[i] == 0) {
			for (int j = i * i; j <= 1000000; j += i) {
				is_prime[j] = 1;
			}
		}
	}
	for (int i = 2; i <= 1000000; i++) {
		if (is_prime[i] == 0) prime.push_back(i);
	}
	int p_size = prime.size();

	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	// 소인수분해
	// [i][j] = num[i]에 대해 prime[j]의 개수
	vector<vector<int>> num_prime_cnt(n, vector<int>(p_size, 0));
	// [j] = prime[j]의 전체 개수, 분배 기준
	vector<int> all_prime_cnt(p_size, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p_size; j++) {
			if (num[i] % prime[j] == 0) {
				while (1) {
					if (num[i] % prime[j] != 0) break;

					num_prime_cnt[i][j]++;
					all_prime_cnt[j]++;
					num[i] /= prime[j];
				}
			}
		}
	}

	// 점수, 변경 횟수 계산
	int score = 1;
	int change = 0;
	for (int j = 0; j < p_size; j++) {
		if (all_prime_cnt[j] / n) {
			// 분배 필요한 경우
			int cnt = all_prime_cnt[j] / n;
			for (int i = 0; i < n; i++) {
				if (num_prime_cnt[i][j] < cnt) {
					change += (cnt - num_prime_cnt[i][j]);
				}
			}
			score *= (int)(pow(prime[j], cnt));
		}
	}

	cout << score << ' ' << change << '\n';
	
	return 0;
}