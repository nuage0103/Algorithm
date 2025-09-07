#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string target;

	int cnt = 0;
	cin >> target >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int pos[10];
		int p = 0;
		int x = -1;
		while (1) {
			p = str.find(target[0], p);
			if (p == string::npos) break;
			pos[++x] = p++;
		}
		if (x == -1) continue;

		bool found = false;
		while (x >= 0) {
			if (found) break;
			int idx = pos[x--];
	
			for (int j = 0; j < target.length(); j++) {
				if (str[(idx + j) % str.length()] != target[j]) break;
				if (j == target.length() - 1) found = true;
			}
		}
		if (found) cnt++;
	}

	cout << cnt << '\n';
	
	return 0;
}
