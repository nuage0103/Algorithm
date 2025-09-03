#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	int len = str.length();

	int a_cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'a') a_cnt++;
	}
	
	int res = INT_MAX;
	// a개수 = 윈도우 크기
	for (int start = 0; start < len; start++) {
		int b_cnt = 0;
		for (int end = start; end < start + a_cnt; end++) {
			if (str[end % len] == 'b') b_cnt++;
		}
		res = min(res, b_cnt);
	}

	cout << res << '\n';
	return 0;
}
