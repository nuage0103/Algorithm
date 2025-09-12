#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, t;
	while (cin >> s >> t) {
		int s_idx = 0;
		for (int i = 0; i < t.length(); i++) {
			if (t[i] == s[s_idx]) {
				s_idx++;
			}

			if (s_idx == s.length()) break;
		}

		if (s_idx == s.length()) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}