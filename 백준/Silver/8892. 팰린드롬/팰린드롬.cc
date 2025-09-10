#include <iostream>
#include <vector>
using namespace std;

bool p_check(string str) {
	int len = str.length();
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - 1 - i]) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<string> str(n);
		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}

		string res;
		bool found = false;
		for (int i = 0; i < n ; i++) {
			if (found) break;
			for (int j = 0; j < n; j++) {
				if (i == j) continue;

				if (p_check(str[i] + str[j])) {
					res = str[i] + str[j];
					found = true;
					break;
				}
			}
		}

		if (found) cout << res << '\n';
		else cout << "0\n";
	}

	return 0;
}