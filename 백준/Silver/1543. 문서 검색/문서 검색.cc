#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, target;
	getline(cin, s);
	getline(cin, target);

	int pos = 0;
	int cnt = 0;
	int t_len = target.length();
	while (1) {
		pos = s.find(target, pos);
		if (pos == string::npos) break;

		cnt++;
		pos += t_len;
	}
	
	cout << cnt << '\n';

	return 0;
}