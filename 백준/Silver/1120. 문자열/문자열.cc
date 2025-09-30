#include <iostream>
#include <vector>
using namespace std;

int find_diff(string a, string b) {
	int diff = 0;
	for (int i = 0; i < b.length(); i++) {
		if (a[i] != b[i]) diff++;
	}

	return diff;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;

	// a.len = b.len
	if (a.length() == b.length()) {
		cout << find_diff(a, b) << '\n';
		return 0;
	}

	// a.len < b.len
	// x+a / a+x
	int a_len = a.length();
	int b_len = b.length();
	int diff = b_len - a_len;
	vector<string> new_a;
	for (int head = 0; head <= diff; head++) {
		// a 앞에 추가할 b 부분문자열
		string head_b = b.substr(0, head);
		string tmp = head_b + a;
		
		// a 뒤에 추가할 b 부분문자열
		string tail_b = b.substr(b_len - (diff - head));
		tmp = tmp + tail_b;

		new_a.push_back(tmp);
	}

	int res = 51;
	for (int i = 0; i < new_a.size(); i++) {
		res = min(res, find_diff(new_a[i], b));
	}
	cout << res << '\n';
	
	return 0;
}