#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	cin.ignore(); // 버퍼에 남은 개행문자 제거

	for (int i = 1; i <= n; i++) {
		int res = 0;
		int alpha[26] = { 0 }; // 알파벳 별 사용개수
		string s;
		getline(cin, s);

		for (int j = 0; j < s.length(); j++) {
			if (s[j] >= 'a' && s[j] <= 'z') {
				alpha[s[j] - 'a']++;
			}
			if (s[j] >= 'A' && s[j] <= 'Z') {
				alpha[s[j] - 'A']++;
			}
		}

		int cnt = alpha[0];
		for (int j = 1; j < 26; j++) {
			cnt = min(cnt, alpha[j]);
		}

		cout << "Case " << i;
		if (cnt == 3) cout << ": Triple pangram!!!\n";
		else if (cnt == 2) cout << ": Double pangram!!\n";
		else if (cnt == 1) cout << ": Pangram!\n";
		else  cout << ": Not a pangram\n";
	}

	return 0;
}