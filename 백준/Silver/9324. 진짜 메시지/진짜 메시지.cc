#include <iostream>
using namespace std;

bool check(string str) {
	int freq[26] = { 0 };

	for (int i = 0; i < str.length(); i++) {
		char cur = str[i] - 'A';
		// 3번째로 쓰일때 바로 연이어 동일한 대문자 나와야함
		freq[cur]++;
		if (freq[cur] == 3) {
			if (str[i + 1] != str[i] || i == str.length() - 1) {
				return false;
			}
			freq[cur] = -1; // 규칙에 의해 추가된 문자 제외하고 개수 세기
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string inp;
		cin >> inp;

		bool res = check(inp);
		if (res) cout << "OK\n";
		else cout << "FAKE\n";
	}

	return 0;
}