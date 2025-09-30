#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> digit(n);
	for (int i = 0; i < n; i++) {
		cin >> digit[i];
	}

	vector<vector<long long>> dp(n - 1, vector<long long>(21, 0));
	// dp[i][j] = k: i번째 연산, 중간 결과 j일때 경우의수 k
	// j = 0~20
	dp[0][digit[0]] = 1;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i-1][j]) {
				if (j + digit[i] <= 20) dp[i][j + digit[i]] += dp[i - 1][j];
				if (j - digit[i] >= 0) dp[i][j - digit[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[n - 2][digit[n - 1]] << '\n';
	
	return 0;
}