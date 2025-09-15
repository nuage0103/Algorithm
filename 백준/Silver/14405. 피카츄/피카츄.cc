#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	string t1 = "pi";
	string t2 = "ka";
	string t3 = "chu";
	
	int cnt = 0;
	int len = s.length();
	int pos = -1;
	while (1) {
		pos = s.find(t1, pos + 1);
		if (pos == string::npos) break;

		cnt += 2;
	}
	if (cnt == len) {
		cout << "YES\n";
		return 0;
	}

	pos = -1;
	while (1) {
		pos = s.find(t2, pos + 1);
		if (pos == string::npos) break;

		cnt += 2;
	}
	if (cnt == len) {
		cout << "YES\n";
		return 0;
	}

	pos = -1;
	while (1) {
		pos = s.find(t3, pos + 1);
		if (pos == string::npos) break;

		cnt += 3;
	}

	if (cnt == len) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}